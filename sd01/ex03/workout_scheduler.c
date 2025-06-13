#include "workout_scheduler.h"

struct WorkoutPlan *create_workout_schedule(char *username)
{
	struct UserData 	*user_data;
	struct WorkoutPlan 	*workout_p;
	struct WorkoutPlan 	*work;
	int 				duration;

	user_data = get_user_data(username);
	if (user_data == NULL)
		return (NULL);
	workout_p = build_base_plan(user_data);
	if(workout_p == NULL)
		return(NULL);
	work = refine_plan(workout_p, user_data);
	if(work == NULL)
		return(NULL);
	duration = determine_duration(work);
	assign_daily_exercises(work, duration);
	assign_daily_tips(work, duration);
	free_user_data(user_data);
	free_workout_plan(workout_p);
	return (work);
}