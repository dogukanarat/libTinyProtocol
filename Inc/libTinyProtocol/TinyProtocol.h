#ifndef INCLUDED_LIBTINYPROTOCOL_H
#define INCLUDED_LIBTINYPROTOCOL_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define LIBTP_HEADER_SYNC             (uint16_t)(0xF00F)
#define LIBTP_MAX_CALLBACK_COUNT      256

#define LIBTP_SUCCESS                  0
#define LIBTP_INVALIDPARAM             -1
#define LIBTP_CALLBACKFULL             -2

#define LIBTP_NODATA                   uint8_t noData[0]

/// @brief
typedef void(*TinyProtocolCallback)(void *pContext, void *pDataSource, uint32_t nDataSourceSize);

/// @brief
typedef struct _TinyProtocolInit
{
    void *pBuffer;
    uint32_t nBufferSize;
} TinyProtocolInit;

/// @brief
typedef struct _TinyProtocolCallbackItem
{
    uint16_t nId;
    TinyProtocolCallback pfnCallback;
} TinyProtocolCallbackItem;

/// @brief
typedef struct _TinyProtocolHeader
{
    uint16_t nSync;             // 
    uint16_t nId;               // 
    uint32_t nSize;             // message size including data and header
} TinyProtocolHeader;

/// @brief
typedef struct _TinyProtocolAbstractMessage
{
    TinyProtocolHeader header;
    uint8_t data[0];
} TinyProtocolAbstractMessage;

/// @brief 
typedef struct _TinyProtocol
{
    TinyProtocolInit init;
    TinyProtocolCallbackItem pCallbackMap[LIBTP_MAX_CALLBACK_COUNT];
    uint32_t nCallbackCount;
} TinyProtocol;

/// @brief this function is used to initialize TinyProtocol instance
/// @param self TinyProtocol instance
/// @param init TinyProtocolInit instance
/// @return 
int32_t tinyProtocolInitialize(TinyProtocol *self, TinyProtocolInit init);

/// @brief this function is used register callback function
/// @param self TinyProtocol instance
/// @param nId message id
/// @param pfnCallback callback function
/// @return
int32_t tinyProtocolRegisterCallback(TinyProtocol *self, uint16_t nId, TinyProtocolCallback pfnCallback);

/// @brief this function is signal TinyProtocol instance to handle new data
/// @param self TinyProtocol instance
/// @param pDataSource data source
/// @param nDataSourceSize data source size
/// @return
int32_t tinyProtocolCallback(TinyProtocol *self, void *pDataSource, uint32_t nDataSourceSize);

/// @brief 
/// @param self 
/// @return 
int32_t tinyProtocolMain(TinyProtocol *self);

#ifdef __cplusplus
}
#endif

#endif