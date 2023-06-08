#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DataStructuresFromScratchUnitTests
{
	TEST_CLASS(AllocatorUnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			constexpr std::size_t size = 5;
			kits::allocator<int> allocator;
			int* arr = allocator.allocate(size);
			Assert::IsNotNull(arr);

			for (int i = 0; i < size; ++i) {
				allocator.construct(arr + i, i);
			}

			for (int i = 0; i < size; ++i) {
				Assert::AreEqual(arr[i], i);
			}

			for (int i = 0; i < size; ++i) {
				allocator.destroy(arr);
			}

			allocator.deallocate(arr);
		}
	};

	TEST_CLASS(VectorUnitTests)
	{
	public:

		TEST_METHOD(create_empty_vector_int)
		{
			kits::vector<int> _v;
		}

		TEST_METHOD(create_empty_vector_and_add_one_int)
		{
			kits::vector<int> v;
			v.push_back(5);
		}
	};
}
