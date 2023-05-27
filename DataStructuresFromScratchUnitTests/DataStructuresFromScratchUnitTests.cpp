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

		TEST_METHOD(TestMethod1)
		{
		}
	};
}
