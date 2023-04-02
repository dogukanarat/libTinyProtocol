#include "libTinyProtocol/TinyProtocol.h"

static int32_t tinyProtocolGetCallback(TinyProtocol *self, uint16_t nId, TinyProtocolCallback *pfnCallback);

int32_t tinyProtocolInitialize(TinyProtocol *self, TinyProtocolInit init)
{
    int32_t status = LIBTP_SUCCESS;

    for (;;)
    {
        if (self == NULL)
        {
            status = LIBTP_INVALIDPARAM;
            break;
        }

        self->init = init;
        self->nCallbackCount = 0;

        break;
    }

    return status;
}

int32_t tinyProtocolRegisterCallback(TinyProtocol *self, uint16_t nId, TinyProtocolCallback pfnCallback)
{
    int32_t status = LIBTP_SUCCESS;

    for (;;)
    {
        if (self == NULL)
        {
            status = LIBTP_INVALIDPARAM;
            break;
        }

        if (self->nCallbackCount >= LIBTP_MAX_CALLBACK_COUNT)
        {
            status = LIBTP_CALLBACKFULL;
            break;
        }

        self->pCallbackMap[self->nCallbackCount].nId = nId;
        self->pCallbackMap[self->nCallbackCount].pfnCallback = pfnCallback;
        self->nCallbackCount++;

        break;
    }

    return status;
}

int32_t tinyProtocolHandleNewData(TinyProtocol *self, void *pDataSource, uint32_t nDataSourceSize)
{
    int32_t status = LIBTP_SUCCESS;

    for (;;)
    {

        break;
    }

    return status;
}

int32_t tinyProtocolMain(TinyProtocol *self)
{
    int32_t status = LIBTP_SUCCESS;

    for (;;)
    {

        break;
    }

    return status;
}

int32_t tinyProtocolGetCallback(TinyProtocol *self, uint16_t nId, TinyProtocolCallback *pfnCallback)
{
    int32_t status = LIBTP_SUCCESS;

    for (;;)
    {
        if (self == NULL)
        {
            status = LIBTP_INVALIDPARAM;
            break;
        }

        if (pfnCallback == NULL)
        {
            status = LIBTP_INVALIDPARAM;
            break;
        }

        for (uint32_t i = 0; i < self->nCallbackCount; i++)
        {
            if (self->pCallbackMap[i].nId == nId)
            {
                *pfnCallback = self->pCallbackMap[i].pfnCallback;
                break;
            }
        }

        break;
    }

    return status;
}