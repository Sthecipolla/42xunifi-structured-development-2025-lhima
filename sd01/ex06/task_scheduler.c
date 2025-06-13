#include "task_scheduler.h"

struct ScheduleResult	*schedule_result(struct tasklist *task)
{
	struct TaskProfile 		*profile;
	struct ScheduleResult	*result;
	int						core_id;
	int						task_id;

	profile = profile_tasks(task);
	free_priority_map(compute_priorities_mock(profile));
	core_id = get_available_core_count();
	task_id = select_best_task(profile);
	result = create_schedule_result(core_id);
	update_schedule_entry(result, core_id, task_id);
	free_task_profile(profile);
	return (result);
}