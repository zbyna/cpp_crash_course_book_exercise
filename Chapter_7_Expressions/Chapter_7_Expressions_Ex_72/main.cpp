#include <cstddef>
#include <iostream>
#include <new>
#include <stdexcept>
#include <windows.h>

// 7-2. Create a LargeBucket class that can store up to 1MB of data. Extend the Heap class so it gives out a LargeBucketfor
// allocations greater than 4096 bytes.  Make sure that you still throw std::bad_alloc whenever the Heap is unable to allocate an
// appropriately sized bucket.

struct Bucket {
    const static size_t data_size{ 4096 };
    std::byte data[data_size];
};

struct LargeBucket {
    const static size_t data_size{ 1048576 }; // 1048576  is 1MB is 2 na 10ou
    std::byte data[data_size];
};

struct Heap {

    static const size_t n_heap_buckets{ 10 };
    Bucket buckets[n_heap_buckets]{};
    bool bucket_used[n_heap_buckets]{};

    static const size_t n_heap_largeBuckets{ 10 };
    LargeBucket largeBuckets[n_heap_largeBuckets]{};
    bool largeBucket_used[n_heap_largeBuckets]{};

    void* allocate(size_t bytes) {
        if(bytes > LargeBucket::data_size) {
            throw std::bad_alloc();
        } else if(bytes > Bucket::data_size) {
            for(size_t i{}; i < n_heap_largeBuckets; i++) {
                if(!largeBucket_used[i]) {
                    largeBucket_used[i] = true;
                    std::cout << "largeBucket (1 Mbyte 0x100000 2na20 16na5) allocated ! \n";
                    return largeBuckets[i].data;
                }
            }
            throw std::bad_alloc{};
        } else {
            for(size_t i{}; i < n_heap_buckets; i++) {
                if(!bucket_used[i]) {
                    bucket_used[i] = true;
                    std::cout << "Bucket (4096 bytes  0x1000 2na12 16n3) allocated ! \n";
                    return buckets[i].data;
                }
            }
            throw std::bad_alloc{};
        }
    }

    void free(void* p) {
        for(size_t i{}; i < n_heap_buckets; i++) {
            if(buckets[i].data == p) {
                bucket_used[i] = false;
                std::cout << "Bucket dealocated ! \n";
                return;
            }
            if(largeBuckets[i].data == p) {
                largeBucket_used[i] = false;
                std::cout << "LargeBucket dealocated ! \n";
                return;
            }
        }
    }
};

struct Supper { // to test LargeBucket allocation
    const static size_t numberOfChar{ 100000 };
    char pole[numberOfChar]{ '5' };
};

Heap heap;

void* operator new(size_t n_bytes) {
    return heap.allocate(n_bytes);
}

// had to add extra compile flag -fno-sized-deallocation to get rid off warning(I am treet all as errors) :
//  "... the program should also define void operator delete(void*, std::size_t) "
void operator delete(void* p) {
    return heap.free(p);
}

int main() {
    std::cout << "Buckets:        " << heap.buckets << "\n";
    std::cout << "LargeBuckets:   " << heap.largeBuckets << "\n";
    auto breakfast = new unsigned int{ 0xC0FFEE };
    auto dinner = new unsigned int{ 0xDEADBEEF };
    auto supper = new Supper{};
    auto postSupper = new Supper{};
    std::cout << "Breakfast:     " << breakfast << " " << std::hex << sizeof(*breakfast) << "\n";
    std::cout << "Dinner:        " << dinner << " " << std::hex << sizeof(*dinner) << "\n";
    std::cout << "Supper:        " << supper << " " << std::hex << sizeof(*supper) << "\n";
    std::cout << "PostSupper:    " << postSupper << " " << std::hex << sizeof(*postSupper) << "\n";
    delete breakfast;
    delete dinner;
    delete supper;
    delete postSupper;
    try {
        while(true) {
            new char;
            std::cout << "Allocated a char.\n";
        }
    } catch(const std::bad_alloc&) {
        std::cout << "std::bad_alloc caught.\n";
    }
}