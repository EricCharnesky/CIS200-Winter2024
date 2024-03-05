#include "pch.h"
#include "CppUnitTest.h"
#include "..\Project1\MagicCharacter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Project1Test
{
	TEST_CLASS(Project1Test)
	{
	public:

		TEST_METHOD(TestMethodCharacterConstructor)
		{
			// Arrange
			string expectedName = "name";
			int expectedMaxHitPoints = 10;
			int expectedCurrentHitPoints = 10;
			int expectedDexterity = 10;
			int expectedXLocation = 10;
			int expectedYLocation = 10;
			Weapon* expectedWeapon = nullptr;

			// Act
			Character character(expectedName, expectedMaxHitPoints, expectedCurrentHitPoints, expectedDexterity, expectedXLocation, expectedYLocation, expectedWeapon);
			string actualName = character.getName();
			int actualMaxHitPoints = character.getMaxHitPoints();
			int actualCurrentHitPoints = character.getCurrentHitPoints();
			int actualDexterity = character.getDexterity();
			int actualXLocation = character.getXLocation();
			int actualYLocation = character.getYLocation();
			Weapon* actualWeapon = character.getWeapon();

			// Assert
			Assert::AreEqual(expectedName, actualName);
			Assert::AreEqual(expectedMaxHitPoints, actualMaxHitPoints);
			Assert::AreEqual(expectedCurrentHitPoints, actualCurrentHitPoints);
			Assert::AreEqual(expectedDexterity, actualDexterity);
			Assert::AreEqual(expectedXLocation, actualXLocation);
			Assert::AreEqual(expectedYLocation, actualYLocation);
			Assert::IsTrue(expectedWeapon == actualWeapon);

		}

		TEST_METHOD(TestMethodCharacterTakeDamage)
		{
			// Arrange
			string expectedName = "name";
			int expectedMaxHitPoints = 10;
			int expectedCurrentHitPoints = 0;
			int expectedDexterity = 10;
			int expectedXLocation = 10;
			int expectedYLocation = 10;
			Weapon* expectedWeapon = nullptr;
			Character character(expectedName, expectedMaxHitPoints, expectedMaxHitPoints, expectedDexterity, expectedXLocation, expectedYLocation, expectedWeapon);

			// Act
			character.takeDamage(expectedMaxHitPoints * 2);
			int actualCurrentHitPoints = character.getCurrentHitPoints();
			

			// Assert
			Assert::AreEqual(expectedCurrentHitPoints, actualCurrentHitPoints);

		}

		TEST_METHOD(TestMethodCharacterTakeNegativeDamage)
		{
			// Arrange
			string expectedName = "name";
			int expectedMaxHitPoints = 10;
			int expectedCurrentHitPoints = 10;
			int expectedDexterity = 10;
			int expectedXLocation = 10;
			int expectedYLocation = 10;
			Weapon* expectedWeapon = nullptr;
			Character character(expectedName, expectedMaxHitPoints, 0, expectedDexterity, expectedXLocation, expectedYLocation, expectedWeapon);

			// Act
			character.takeDamage(-(expectedMaxHitPoints * 2));
			int actualCurrentHitPoints = character.getCurrentHitPoints();


			// Assert
			Assert::AreEqual(expectedCurrentHitPoints, actualCurrentHitPoints);

		}

		TEST_METHOD(TestMethodCharacterAttack)
		{
			// Arrange
			string expectedName = "name";
			int expectedMaxHitPoints = 10;
			int expectedCurrentHitPoints = 9;
			int expectedDexterity = 0;
			int expectedXLocation = 10;
			int expectedYLocation = 10;
			Weapon* expectedWeapon = nullptr;
			Character character(expectedName, expectedMaxHitPoints, expectedMaxHitPoints, expectedDexterity, expectedXLocation, expectedYLocation, expectedWeapon);
			Character target(expectedName, expectedMaxHitPoints, expectedMaxHitPoints, expectedDexterity, expectedXLocation, expectedYLocation, expectedWeapon);

			// Act
			character.attack(&target);
			int actualCurrentHitPoints = target.getCurrentHitPoints();


			// Assert
			Assert::AreEqual(expectedCurrentHitPoints, actualCurrentHitPoints);

		}

		TEST_METHOD(TestMethodCharacterAttackNotWithinRange)
		{
			// Arrange
			string expectedName = "name";
			int expectedMaxHitPoints = 10;
			int expectedCurrentHitPoints = 10;
			int expectedDexterity = 0;
			int expectedXLocation = 10;
			int expectedYLocation = 10;
			Weapon* expectedWeapon = nullptr;
			Character character(expectedName, expectedMaxHitPoints, expectedMaxHitPoints, expectedDexterity, expectedXLocation, expectedYLocation, expectedWeapon);
			Character target(expectedName, expectedMaxHitPoints, expectedMaxHitPoints, expectedDexterity, expectedXLocation, expectedYLocation*2, expectedWeapon);

			// Act
			character.attack(&target);
			int actualCurrentHitPoints = target.getCurrentHitPoints();


			// Assert
			Assert::AreEqual(expectedCurrentHitPoints, actualCurrentHitPoints);

		}

		TEST_METHOD(TestMethodMagicCharacterAttack)
		{
			// Arrange
			string expectedName = "name";
			int expectedMaxHitPoints = 10;
			int expectedCurrentHitPoints = 7;
			int expectedDexterity = 0;
			int expectedXLocation = 10;
			int expectedYLocation = 10;
			int expectedIntelligence = 10;
			Weapon* expectedWeapon = nullptr;
			MagicCharacter character(expectedName, expectedMaxHitPoints, expectedMaxHitPoints, expectedDexterity, expectedXLocation, expectedYLocation, expectedWeapon, 10);
			Character target(expectedName, expectedMaxHitPoints, expectedMaxHitPoints, expectedDexterity, expectedXLocation, expectedYLocation * 2, expectedWeapon);

			// Act
			character.attack(&target);
			int actualCurrentHitPoints = target.getCurrentHitPoints();


			// Assert
			Assert::AreEqual(expectedCurrentHitPoints, actualCurrentHitPoints);

		}
	};
}
