#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <ram-err.h>

int main() {
    struct timeval tv;
	struct tm time;
    perr_die_if(gettimeofday(&tv, NULL) != 0, "gettimeofday");
    perr_die_if(gmtime_r((time_t *)&tv, &time) == NULL, "gmtime_r");

    char buffer[32] = {0};

	strftime(buffer, sizeof(buffer), "%Y-%m-%dT%TZ", &time);

    puts(buffer);

    return 0;
}
