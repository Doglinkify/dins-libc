#ifndef __SYS_DLOS_PRIVATE_H__
#define __SYS_DLOS_PRIVATE_H__

#define INFO_CONSOLE_COLS 0
#define INFO_CONSOLE_ROWS 1
#define INFO_PID 2
#define INFO_TICKS 3
#define INFO_CONSOLE_ECHO_OFF 4
#define INFO_CONSOLE_ECHO_ON 5

unsigned long long dlos_sys_info(unsigned long long);

#endif
