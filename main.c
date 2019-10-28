/*
 * @FileName: 
 * @Descripttion: 
 * @Author: jiangfeng.zhang(jiangfeng.zhang@aliyun.com)
 * @LastEditTime: 2019-10-28 11:49:52
 */

#include <stdio.h>
#include "pthread.h"
#include "mqtt.h"
#include "unistd.h"

int main(int argc, char *argv[])
{
    pthread_t thread_ID;		//定义线程id

    pthread_create(&thread_ID, NULL, &cloud_mqtt_thread, NULL);	//创建一个线程执行mqtt客户端
    pthread_detach(thread_ID);	//设置线程结束收尸

    while (1) {
        mqtt_data_write("my yes", 6, 0);//循环向发布主题发送消息
        sleep(3);						//睡眠3s
    }

    return 0;
}
