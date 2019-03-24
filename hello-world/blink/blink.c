
/**
 * @file blink.c
 * @author Joetu (tuweidongg@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2019-01-20
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#define LOG_TAG "blink"

#include <elog.h>

#include "stdio.h"
#include "wiringPi.h"

#define PIN_LED_BLUE 0
#define PIN_LED_GREEN 2

static void test_elog(void);

int main(int argc, char const *argv[])
{

    /* initialize EasyLogger */
    elog_init();
    /* set EasyLogger log format */
    elog_set_fmt(ELOG_LVL_ASSERT, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_ERROR, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_WARN, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_INFO, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_ALL & ~ELOG_FMT_FUNC);
    elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL & ~ELOG_FMT_FUNC);
#ifdef ELOG_COLOR_ENABLE
    elog_set_text_color_enabled(true);
#endif
    /* start EasyLogger */
    elog_start();

    wiringPiSetup();
    pinMode(PIN_LED_GREEN, OUTPUT);
    pinMode(PIN_LED_BLUE, OUTPUT);
    for (;;)
    {
        digitalWrite(PIN_LED_BLUE, HIGH);
        delay(200);
        log_i("led blue on");
        digitalWrite(PIN_LED_BLUE, LOW);
        delay(200);
        log_i("led blue off");

        digitalWrite(PIN_LED_GREEN, HIGH);
        delay(200);
        log_i("led green on");
        digitalWrite(PIN_LED_GREEN, LOW);
        delay(200);
        log_i("led green off");
    }
    return 0;
}

/**
 * EasyLogger demo
 */
void test_elog(void)
{
    uint8_t buf[256] = {0};
    int i = 0;

    for (i = 0; i < sizeof(buf); i++)
    {
        buf[i] = i;
    }
    while (true)
    {
        /* test log output for all level */
        log_a("Hello EasyLogger!");
        log_e("Hello EasyLogger!");
        log_w("Hello EasyLogger!");
        log_i("Hello EasyLogger!");
        log_d("Hello EasyLogger!");
        log_v("Hello EasyLogger!");
        //        elog_raw("Hello EasyLogger!");
        elog_hexdump("test", 16, buf, sizeof(buf));
        sleep(5);
    }
}
