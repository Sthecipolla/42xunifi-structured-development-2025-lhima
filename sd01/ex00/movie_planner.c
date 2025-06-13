#include "movie_planner.h"

struct Plan *create_movie_night_plan(void)
{
	struct Preferences *pref;
	struct MovieList *mlist;
	struct Plan *plan;

	pref = get_user_preferences();
	mlist = find_movies(pref);
	plan = build_plan(mlist);
	free(pref);
	free(mlist);
	return (plan);
}