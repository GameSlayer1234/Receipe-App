#include<iostream>
#include<vector>
#include<fstream>
#include<string>

struct Recipe
{
	std::string recipe_name;
	std::string ingredients;
	std::string instructions;
};

std::vector<Recipe> recipes;

void display_menu()
{
	std::cout << "1.Add Recipe" << std::endl;
	std::cout << "2.View Recipes" << std::endl;
	std::cout << "3.Exit" << std::endl;
	std::cout << "Enter your choice" << std::endl;
}

void addRecipe()
{
	Recipe recipe;
	std::cout << "Enter recipe name" << std::endl;
	std::getline(std::cin, recipe.recipe_name);

	std::cout << "Enter ingredients (seperate each items with comma)" << std::endl;
	std::getline(std::cin, recipe.ingredients);

	std::cout << "Enter instructions on how to cook" << std::endl;
	std::getline(std::cin, recipe.instructions);

	recipes.push_back(recipe);
	std::cout << "Recipe added successfully" << std::endl;
}

void viewRecipes()
{
	if (recipes.empty())
	{
		std::cout << "No recipes available. Please add recipes first" << std::endl;
		return;
	}
	for (size_t i = 0; i < recipes.size(); ++i)
	{
		std::cout << "Recipe # " << i + 1 << std::endl;
		std::cout << "Name: " << recipes[i].recipe_name << std::endl;
		std::cout << "Ingredients: " << recipes[i].ingredients << std::endl;
		std::cout << "Instructions: " << recipes[i].instructions << std::endl;
		std::cout << "_____________________________________________" << std::endl;
	}
}

void saveRecipestoFile()
{
	std::ofstream outfile("recipes.txt");

	if (!outfile)
	{
		std::cout << "Error: Cannot open file for writing" << std::endl;
		return;
	}

	for (const auto& recipe : recipes)
	{
		outfile << recipe.recipe_name << std::endl;
		outfile << recipe.ingredients << std::endl;
		outfile << recipe.instructions << std::endl;
	}
	outfile.close();
}

void loadrecipesfromfile()
{
	std::ifstream infile("recipes.txt");

	if (!infile)
	{
		std::cout << "No saved recipes found" << std::endl;
		return;
	}

	Recipe recipe;

	while (std::getline(infile, recipe.recipe_name))
	{
		std::getline(infile, recipe.ingredients);
		std::getline(infile, recipe.instructions);
		recipes.push_back(recipe);
	}
	infile.close();
}

int main()
{
	loadrecipesfromfile();

	int choice;

	do
	{
		display_menu();
		std::cin >> choice;

		std::cin.ignore();

		switch (choice)
		{
		case 1:
			addRecipe();
			break;

		case 2:
			viewRecipes();
			break;

		case 3:
			saveRecipestoFile();
			std::cout << "GOODBYE!!!!!!!" << std::endl;
			break;

		default:
			std::cout << "Please enter a valid choice!" << std::endl;
		}

	} while (choice != 3);
	return 0;
}