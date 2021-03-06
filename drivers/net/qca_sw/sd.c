/*
 * Copyright (c) 2012 Qualcomm Atheros, Inc.
 * All rights reserved.
 * Qualcomm Atheros Confidential and Proprietary.
 *
 */
#include "sw.h"
#include "ssdk_init.h"
#include "sd.h"
#if (defined(KERNEL_MODULE) && defined(USER_MODE))
#include "sw_api.h"
#include "sw_api_us.h"
#endif

mdio_reg_set ssdk_mdio_set    = NULL;
mdio_reg_get ssdk_mdio_get    = NULL;
hdr_reg_set  ssdk_hdr_reg_set = NULL;
hdr_reg_get  ssdk_hdr_reg_get = NULL;

sw_error_t
sd_reg_mdio_set(a_uint32_t dev_id, a_uint32_t phy, a_uint32_t reg,
                a_uint16_t data)
{
    sw_error_t rv = SW_OK;

    if (NULL != ssdk_mdio_set)
    {
        rv = ssdk_mdio_set(dev_id, phy, reg, data);
    }
    else
    {
#if ((!defined(KERNEL_MODULE)) && defined(UK_IF))
        {
            a_uint32_t args[SW_MAX_API_PARAM];

            args[0] = SW_API_PHY_SET;
            args[1] = (a_uint32_t) & rv;
            args[2] = dev_id;
            args[3] = phy;
            args[4] = reg;
            args[5] = data;
            if (SW_OK != sw_uk_if(args))
            {
                return SW_FAIL;
            }
        }
#else
        return SW_NOT_SUPPORTED;
#endif
    }

    return rv;
}

sw_error_t
sd_reg_mdio_get(a_uint32_t dev_id, a_uint32_t phy, a_uint32_t reg, a_uint16_t * data)
{
    sw_error_t rv = SW_OK;

    if (NULL != ssdk_mdio_get)
    {
        rv = ssdk_mdio_get(dev_id, phy, reg, data);
    }
    else
    {
#if ((!defined(KERNEL_MODULE)) && defined(UK_IF))
        {
            a_uint32_t args[SW_MAX_API_PARAM];
            a_uint32_t tmp;

            args[0] = SW_API_PHY_GET;
            args[1] = (a_uint32_t) & rv;
            args[2] = dev_id;
            args[3] = phy;
            args[4] = reg;
            args[5] = (a_uint32_t) & tmp;
            if (SW_OK != sw_uk_if(args))
            {
                return SW_FAIL;
            }
            *data = *((a_uint16_t *)&tmp);
        }
#else
        return SW_NOT_SUPPORTED;
#endif
    }

    return rv;
}

sw_error_t
sd_reg_hdr_set(a_uint32_t dev_id, a_uint32_t reg_addr, a_uint8_t * reg_data, a_uint32_t len)
{
    sw_error_t rv;

    if (NULL != ssdk_hdr_reg_set)
    {
        rv = ssdk_hdr_reg_set(dev_id, reg_addr, reg_data, len);
    }
    else
    {
        return SW_NOT_SUPPORTED;
    }

    return rv;
}

sw_error_t
sd_reg_hdr_get(a_uint32_t dev_id, a_uint32_t reg_addr, a_uint8_t * reg_data, a_uint32_t len)
{
    sw_error_t rv;

    if (NULL != ssdk_hdr_reg_get)
    {
        rv = ssdk_hdr_reg_get(dev_id, reg_addr, reg_data, len);
    }
    else
    {
        return SW_NOT_SUPPORTED;
    }

    return rv;
}

sw_error_t
sd_init(a_uint32_t dev_id, ssdk_init_cfg * cfg)
{
    if (NULL != cfg->reg_func.mdio_set)
    {
        ssdk_mdio_set = cfg->reg_func.mdio_set;
    }

    if (NULL != cfg->reg_func.mdio_get)
    {
        ssdk_mdio_get = cfg->reg_func.mdio_get;
    }

    if (NULL != cfg->reg_func.header_reg_set)
    {
        ssdk_hdr_reg_set = cfg->reg_func.header_reg_set;
    }

    if (NULL != cfg->reg_func.header_reg_get)
    {
        ssdk_hdr_reg_get = cfg->reg_func.header_reg_get;
    }

    return SW_OK;
}

