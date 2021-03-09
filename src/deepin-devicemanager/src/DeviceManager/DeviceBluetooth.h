/*
* Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd.
*
* Author:     Jun.Liu <liujuna@uniontech.com>
*
* Maintainer: XiaoMei.Ji <jixiaomei@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef DEVICEBLUETOOTH_H
#define DEVICEBLUETOOTH_H
#include "DeviceInfo.h"

/**
 * @brief The DeviceBluetooth class
 * 用来描述蓝牙的类
 */
class DeviceBluetooth : public DeviceBaseInfo
{
    Q_OBJECT
    Q_DISABLE_COPY(DeviceBluetooth)
public:
    DeviceBluetooth();

    /**
       * @brief setInfoFromHciconfig:设置由hciconfig命令获取的设备信息
       * @param mapInfo:由hciconfig获取的信息map
       */
    void setInfoFromHciconfig(const QMap<QString, QString> &mapInfo);

    /**
       * @brief setInfoFromHwinfo:设置由hwinfo --sound命令获取的设备信息
       * @param mapInfo:由hwinfo获取的信息map
       * @return 布尔值，true:信息设置成功；false:信息设置失败
       */
    bool setInfoFromHwinfo(const QMap<QString, QString> &mapInfo);

    /**
       * @brief setInfoFromLshw:设置从lshw里面获取的信息
       * @param mapInfo:由lshw获取的信息map
       * @return 布尔值，true:信息设置成功；false:信息设置失败
       */
    bool setInfoFromLshw(const QMap<QString, QString> &mapInfo);

    /**
       * @brief name:获取名称属性值
       * @return QString:名称属性值
       */
    const QString &name() const override;

    /**
       * @brief driver:获取驱动属性值
       * @return QString:驱动属性值
       */
    const QString &driver() const override;

    /**
     * @brief subTitle:获取子标题
     * @return 子标题
     */
    QString subTitle() override;

    /**
     * @brief getOverviewInfo:获取概况信息
     * @return 概况信息
     */
    const QString getOverviewInfo() override;

    /**
     * @brief setEnable 设置设备的禁用状态
     * @param enable 是否禁用
     * @return 禁用是否成功
     */
    EnableDeviceStatus setEnable(bool enable) override;

    /**
     * @brief enable : 判断当前是否是禁用状态
     * @return
     */
    bool enable() override;

protected:
    /**
       * @brief initFilterKey:初始化可现实的可显示的属性,m_FilterKey
       */
    void initFilterKey() override;

    /**
     * @brief loadBaseDeviceInfo:加载基本信息
     */
    void loadBaseDeviceInfo() override;

    /**
     * @brief loadOtherDeviceInfo:加载基本信息
     */
    void loadOtherDeviceInfo() override;

    /**
     * @brief loadTableData:加载表头信息
     */
    void loadTableData() override;

private:
    /**
     * @brief parseKeyToLshw:获取映射到lshw的key
     * @param info:hwinfo 中的SysFS BusID属性值
     */
    void parseKeyToLshw(const QString &info);

private:
    QString m_Name; //<! 【名称】
    QString m_Vendor; //<! 【制造商】
    QString m_Version; //<! 【版本】
    QString m_Model; //<! 【型号】
    QString m_MAC; //<! 【物理地址】
    QString m_LogicalName; //<! 【逻辑名称】
    QString m_BusInfo; //<! 【总线信息】
    QString m_Capabilities; //<! 【功能】
    QString m_Driver; //<! 【驱动】
    QString m_DriverVersion; //<! 【驱动版本】
    QString m_MaximumPower; //<! 【最大功耗】
    QString m_Speed; //<! 【速度】

    QString m_UniqueKey; //<!  鼠标设备的唯一标识
};

#endif // DEVICEBLUETOOTH_H
