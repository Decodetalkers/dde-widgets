// SPDX-FileCopyrightText: 2021 - 2023 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "global.h"
#include <QObject>

#include "display_interface.h"
#include "monitor_interface.h"
#include "dock_interface.h"
WIDGETS_FRAME_BEGIN_NAMESPACE
using DisplayInter = org::deepin::dde::Display1;
using DockInter = org::deepin::dde::daemon::Dock1;

class GeometryHandler : public QObject {
    Q_OBJECT
public:
    explicit GeometryHandler(QObject *parent = nullptr);
    virtual ~GeometryHandler() override;

    QRect getGeometry(const int expectedWidth);

    QRect calcDisplayRect(const QRect &dockRect);
private:
    DisplayInter *m_displayInter = nullptr;
    DockInter *m_dockDeamonInter = nullptr;
};
WIDGETS_FRAME_END_NAMESPACE
