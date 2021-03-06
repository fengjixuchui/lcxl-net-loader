#ifndef _LCXL_NET_CODE_H_
#define _LCXL_NET_CODE_H_

#define JSON_CODE "code"
#define JC_NONE 0x00
//获取模块列表命令
#define JC_MODULE_LIST 0x01
//获取后端服务器列表
#define JC_SERVER_LIST 0x03
//设置虚拟IP地址
#define JC_SET_VIRTUAL_ADDR 0x04
//添加后端服务器
#define JC_ADD_SERVER 0x05
//设置后端服务器
#define JC_SET_SERVER 0x06
//删除后端服务器
#define JC_DEL_SERVER 0x07
//登录服务器
#define JC_LOGON 0x10
//设置负载均衡器的mac地址
//#define JC_SET_ROUTER_MAC_ADDR 0x05

#define JSON_DATA "data"
#define JSON_MODULE_LIST "module_list"
#define JSON_SERVER_LIST "server_list"
#define JSON_MINIPORT_NET_LUID "miniport_net_luid"

#define JSON_STATUS "status"
#define JS_SUCCESS 0x00
#define JS_FAIL 0x01
#define JS_JSON_DATA_NOT_FOUND 0x02
#define JS_JSON_CODE_NOT_FOUND 0x03
#define JS_JSON_CODE_IP_FORMAT_INVALID 0x04
#define JS_JSON_INVALID 0x05

#define JS_UNKNOWN_HOST 0x10;
#define JS_SOCKET_ERROR 0x11;

#endif