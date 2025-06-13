#include "recipe_generator.h"

struct Recipe *create_custom_recipe(void)
{
	struct Recipe 		*recipe;
	struct Ingredients *ingredients;
	struct TasteProfile *user;

	user = get_user_taste_profile();
	if (!user)
		return (NULL);
	ingredients = get_current_ingredients();
	recipe = create_recipe(ingredients, user);
	free_ingredients(ingredients);
	free_taste_profile(*user);
	return (recipe);
}