#include "pch.h"
#include "../DataStructuresFromScratchUnitTests/DataStructuresFromScratchUnitTests.cpp"

int main() {
	using namespace DataStructuresFromScratchUnitTests;
	
	{
		AllocatorUnitTests allocatorUnitTests;
		allocatorUnitTests.TestMethod1();
	}

	{
		VectorUnitTests vectorUnitTests;
		vectorUnitTests.create_empty_vector_int();
	}

	{
		VectorUnitTests vectorUnitTests;
		vectorUnitTests.create_empty_vector_and_add_one_int();
	}
}