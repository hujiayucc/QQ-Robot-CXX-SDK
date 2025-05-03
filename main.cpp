//
// Created by hujiayucc on 25-5-2.
//

#include "main.h"
#include "api.h"
#include "type.h"
#include <cstring>

API char* ZZ_initialize() {
    api = new Api();
    api->Out("C++插件初始化完成", 0x00FF00);
    return const_cast<char*>("{'name':'test','auth':'小宇','version':'1.0.0','explain':'这是一个C++插件示例'}");
}

/**
 * @brief 消息
 * @param botId 机器人ID
 * @param event 消息类型/事件类型
 * @param msgFrom 消息来源
 * @param userId 触发人ID
 * @param msgId 消息ID
 * @param text 消息内容
 * @param file 附件 富媒体文件附件，文件类型："图片，语音，视频，文件"
 * @param json 原始JSON
 * @return 100（继续）
 */
API int ZZ_messages(char *botId, int event, char *msgFrom, char *userId, char *msgId, char *text, char *file, char *json) {
    if (event != EVENT_MSG_PRIVATE && event != EVENT_MSG_PRIVATE2) return EVENT_MSG_CONTINUE;
    if (strcmp(userId, "6B4404468C00AAE64F903724D7F7ECE5") == 0) {
        api->Out(text, 0x00FF00);
        api->Out(api->SendPrivateText(
            botId, userId, "C++插件测试成功", msgId
        ), 0x00FF00);
    }
    return EVENT_MSG_CONTINUE;
}

API int ZZ_Deactivate() {
    return 1;
}

API void ZZ_uninstall() {
    delete api;
}

API int ZZ_set() {
    api->Out("窗口需要自行实现", 0x00FF00);
    return 1;
}