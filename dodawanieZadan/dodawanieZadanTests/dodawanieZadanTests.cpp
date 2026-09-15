#include "pch.h"
#include "pch.cpp"
#include "CppUnitTest.h"
#include "Task.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace dodawanieZadanTests
{
	TEST_CLASS(dodawanieZadanTests)
	{
	public:
		
		TEST_METHOD(editTaskName)
		{
			Task task(1, "stara nazwa", 1);
			task.setName("nowa nazwa");
			Assert::AreEqual(std::string("nownazwa"),task.getName());
		}

		TEST_METHOD(editPriorityName)
		{
			Task task(1, "nauka", 1);
			task.setPriority(3);
			Assert::AreEqual(3, task.getPriority());
		}
	};
}
