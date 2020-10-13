#include<iostream>
class Allocator{
	private:
		char *mem;
		size_t current;
		size_t msize;
	public:
		void makeAllocator(size_t maxSize)
		{
			char buffer[maxSize];
			if (!buffer){
				return;
			}
			mem = buffer;
			current = 0;
			msize = maxSize;
		}
		char* alloc(size_t size)
		{
			if (size <0)
				return nullptr;
			//char *ptr = mem;
			if (size == 0)
				return mem;
			if ( current + size < msize && size!=0){
				mem += size;
				current += size;
				return mem;

			}else{
				return nullptr;
			}  
		}
		void reset()
		{
			mem -= current;
			current = 0;
		}
};



