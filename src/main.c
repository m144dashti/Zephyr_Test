#include <zephyr.h>
#include <device.h>
#include <devicetree.h>
#include <sys/printk.h>
#include <drivers/gpio.h>

/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   200


void main(void)
{
	const struct device *dev;
	int ret;
	dev = device_get_binding("GPIOB");
	ret = gpio_pin_configure(dev, 12, GPIO_OUTPUT_HIGH);
	if (dev == NULL) {
		return;
	}
	if (ret < 0) {
		return;
	}
    

	while (1) {
		k_msleep(SLEEP_TIME_MS);
		gpio_pin_toggle(dev, 12);
		
	}
}

