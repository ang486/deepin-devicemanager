/*
* Copyright (C) 2019 ~ 2020 UnionTech Software Technology Co.,Ltd
*
* Author:      zhangkai <zhangkai@uniontech.com>
* Maintainer:  zhangkai <zhangkai@uniontech.com>
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "../src/Page/PageInfoWidget.h"
#include "../src/DeviceManager/DeviceInput.h"
#include "../src/Page/PageInfo.h"
#include "../src/Page/PageMultiInfo.h"

#include "../tests/ut_Head.h"
#include <QCoreApplication>
#include <QPaintEvent>
#include <QPainter>

#include <gtest/gtest.h>
#include <tests/stub.h>

class PageInfoWidget_UT : public UT_HEAD
{
public:
    virtual void setup()
    {
    }
    void TearDown()
    {
        delete m_pageInfoWidget;
    }
    PageInfoWidget *m_pageInfoWidget = nullptr;
};

TEST_F(PageInfoWidget_UT, PageInfoWidget_UT_updateTable)
{
    m_pageInfoWidget = new PageInfoWidget;
    PageMultiInfo *p = new PageMultiInfo;
    m_pageInfoWidget->mp_PageInfo = dynamic_cast<PageInfo *>(p);
    DeviceInput *device = new DeviceInput;
    QMap<QString, QString> mapinfo;
    mapinfo.insert("/", "/");
    device->setInfoFromHwinfo(mapinfo);
    QList<DeviceBaseInfo *> bInfo;
    bInfo.append(device);
    m_pageInfoWidget->updateTable("", bInfo);
    delete p;
}

TEST_F(PageInfoWidget_UT, PageInfoWidget_UT_updateTable2)
{
    m_pageInfoWidget = new PageInfoWidget;
    PageMultiInfo *p = new PageMultiInfo;
    m_pageInfoWidget->mp_PageInfo = dynamic_cast<PageInfo *>(p);
    QMap<QString, QString> map;
    map.insert("/", "/");
    m_pageInfoWidget->updateTable("", map);
    delete p;
}

TEST_F(PageInfoWidget_UT, PageInfoWidget_UT_resizeEvent)
{
    m_pageInfoWidget = new PageInfoWidget;
    QResizeEvent resizeevent(QSize(10, 10), QSize(10, 10));
    m_pageInfoWidget->resizeEvent(&resizeevent);
}

TEST_F(PageInfoWidget_UT, PageInfoWidget_UT_slotRefreshInfo)
{
    m_pageInfoWidget = new PageInfoWidget;
    m_pageInfoWidget->slotRefreshInfo();
    m_pageInfoWidget->slotExportInfo();
    m_pageInfoWidget->slotUpdateUI();
}
