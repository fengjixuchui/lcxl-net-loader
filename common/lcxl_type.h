﻿#ifndef _LCXL_TYPE_H_
#define _LCXL_TYPE_H_
//author:LCXL
//abstract:驱动和应用程序共用的自定义数据包有关结构数据头文件
//如果是驱动程序，需要前面加头文件lcxl_net.h
//如果是Win32程序，需要前面加WinSock2.h和#include <Ws2ipdef.h>
//#include "driver/lcxl_net.h"
#include <ifdef.h>

#ifdef __cplusplus
extern "C" {
#endif
#define LCXL_ROLE_UNKNOWN	0x00//服务器角色，INT型：未知角色，用于错误处理
#define LCXL_ROLE_ROUTER	0x01//服务器角色，INT型：均衡器，用来分发用户请求
#define LCXL_ROLE_SERVER	0x02//服务器角色，INT型：服务器，用来处理用户请求

	typedef struct _LCXL_IP {
#define IM_UNKNOWN	0//标识此IP为位置IP类型地址
#define IM_IPV4		1//标识此IP为IPv4地址
#define IM_IPV6		2//标识此IP为IPv6地址
		int						ip_mode;		//IP模式，IPv4还是IPv6， IM_IPV4, IM_IPV6
		union {
			IN_ADDR			    ip_4;			//源IPv4地址
			IN6_ADDR			ip_6;			//源IPv6地址
		} addr;//IP地址
	} LCXL_IP, *PLCXL_IP;//自定义的IP结构

	typedef struct _LCXL_ADDR_INFO {
#define SA_ENABLE_IPV4	0x01//服务器启用了IPV4协议
#define SA_ENABLE_IPV6	0x02//服务器启用了IPV6协议
		UCHAR				status;//服务器IP地址情况，有SA_ENABLE_IPV4，和SA_ENABLE_IPV6，可以同时使用
		IN_ADDR				ipv4;//IPv4地址
		UINT8				ipv4_onlink_prefix_length;//IPv4子网掩码长度，在驱动层不使用
		IN6_ADDR			ipv6;//IPv6地址
		UINT8				ipv6_onlink_prefix_length;//IPv6前缀长度，在驱动层不使用
	} LCXL_ADDR_INFO, *PLCXL_ADDR_INFO;//IP地址和MAC地址结构信息

	typedef struct _LCXL_SERVER_PERFORMANCE {
		unsigned long       process_time;//单个任务的平均处理时间，时间单位为微妙（us），Windows下使用KeQueryPerformanceCounter
		unsigned long long  total_memory;//总内存数
		unsigned long long  cur_memory;//当前使用内存
		double              cpu_usage;//CPU使用率，最高为1
		double				request_response_interval;//收到数据包到发送数据包的间隔，用来衡量服务器的响应时间
	} LCXL_SERVER_PERFORMANCE, *PLCXL_SERVER_PERFORMANCE;//服务器性能
	
	typedef struct _LCXL_SERVER {
#define SS_ONLINE	0x01//服务器在线
#define SS_CHECKING	0x02//正在检测服务器的可用性
#define SS_DELETED	0x80//服务器已被删除
		UCHAR				status;//服务器状态，SS_...
		UCHAR				ip_status;//IP协议启用状态，SA_ENABLE_IPV...
		IF_PHYSICAL_ADDRESS mac_addr;//服务器MAC地址
	} LCXL_SERVER, *PLCXL_SERVER;//服务器信息

	typedef struct _LCXL_SERVER_CHECK {
		//设置服务器检测间隔，以秒为单位
		INT					interval;
		//服务器检测超时时间，以秒为单位
		INT					timeout;
		//服务器检测失败时的重试次数
		INT					retry_number;
	} LCXL_SERVER_CHECK, *PLCXL_SERVER_CHECK;//服务器检测设置
//------可用性检测帧类型------
#define ETHERNET_TYPE_LCXL_CHECKING 0xF0F0

#define CHECKING_CODE_NONE		0x00
#define CHECKING_CODE_REQUEST	0x01
#define CHECKING_CODE_RESPONSE	0x02

	//LCXL_CHECKING_HEADER
	typedef struct _LCXL_CHECKING_HEADER {
		UINT16			code;//代码
		LCXL_SERVER_PERFORMANCE preformance;//服务器性能，code=CHECKING_CODE_RESPONSE时可用
	} LCXL_CHECKING_HEADER, *PLCXL_CHECKING_HEADER;

//------路由算法类型------
//静态算法
#define RA_POLL					0x00//轮询算法
#define RA_IP_HASH				0x01//基于IP的hash算法
//动态算法
#define RA_LEAST_CONNECTION		0x10//最小连接数算法
#define RA_FAST_RESPONSE		0x11//最快响应时间算法

#ifdef __cplusplus
}
#endif

#endif