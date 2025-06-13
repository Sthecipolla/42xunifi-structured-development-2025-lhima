#include "food_order.h"

int process_food_order(struct OrderRequest *request)
{
	struct OrderConfirmation *confirm;
	int ret;

	ret = 1;
	if(check_restaurant_status(request) == 1)
	{
		confirm = OrderConfirmation();
		if(confirm == NULL)
			ret = 0;
	}
	else
	{
		confirm = create_preorder_confirmation();
		if(confirm == NULL)
			ret = 0;
	}
	send_confirmation_notification(confirm);
	free(request);
	return (ret);
}