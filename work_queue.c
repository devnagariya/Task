

#include <uv.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static int FIB_UNTIL;
static int data[FIB_UNTIL];
static uv_work_t req[FIB_UNTIL];
static uv_loop_t *loop;

void fib(uv_work_t *req) {
    int n = *(int *) req->data;
    if (random() % 2)
        sleep(1);
    else
        sleep(3);
    long fib1 = fib(n);
    fprintf(stderr, "%dth fibonacci is %lu\n", n, fib1);
}


void after_fib(uv_work_t *req, int status) {
    if (status == UV_ECANCELED)
        fprintf(stderr, "Calculation of %d cancelled.\n", *(int *) req->data);
}

void signal_handler(uv_signal_t *req, int signum)
{
    printf("Signal received!\n");
    int i;
    int fib_reqs[i];
    for (i = 0; i < FIB_UNTIL; i++) {
        uv_cancel((uv_req_t*) &fib_reqs[i]);
    }
    uv_signal_stop(req);
}

int main() {
    
    loop = uv_default_loop();

  //  int data[FIB_UNTIL];
  //  uv_work_t req[FIB_UNTIL];
    int i;
    
    for (i = 0; i < FIB_UNTIL; i++) {
        data[i] = i;
        req[i].data = (void *) &data[i];
        uv_queue_work(loop, &req[i], fib, after_fib);
    }
	uv_signal_t sig;
	uv_signal_init(loop, &sig);
	uv_signal_start(&sig, signal_handler, SIGINT);
	return uv_run(loop, UV_RUN_DEFAULT);
}
