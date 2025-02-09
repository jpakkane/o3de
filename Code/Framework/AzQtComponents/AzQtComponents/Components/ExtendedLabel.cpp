/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include "ExtendedLabel.h"
AZ_PUSH_DISABLE_WARNING(4251 4244, "-Wunknown-warning-option") // 4251: 'QVariant::d': struct 'QVariant::Private' needs to have
                                                               // dll-interface to be used by clients of class 'QVariant'
#include <QVariant>
AZ_POP_DISABLE_WARNING

namespace AzQtComponents
{
    ExtendedLabel::ExtendedLabel(QWidget* parent)
        : QLabel(parent)
    {
    }

    void ExtendedLabel::setPixmap(const QPixmap& p)
    {
        m_pix = p;
        rescale();
    }

    void ExtendedLabel::resizeEvent(QResizeEvent* /*event*/)
    {
        rescale();
    }

    void ExtendedLabel::rescale()
    {
        if (!m_pix.isNull())
        {
            setAlignment(Qt::AlignCenter);

            int realWidth;
            int realHeight;

            m_pixmapSize = property("pixmapSize").toSize();

            if (m_pixmapSize.isValid())
            {
                realWidth = qMin(m_pixmapSize.width(), this->width());
                realHeight = qMin(m_pixmapSize.height(), this->height());
            }
            else
            {
                realWidth = this->width();
                realHeight = this->height();
            }

            double aspectRatioExpected = aspectRatio(realWidth, realHeight);
            double aspectRatioSource = aspectRatio(m_pix.width(), m_pix.height());

            // use the one that fits
            if (aspectRatioExpected > aspectRatioSource)
            {
                QLabel::setPixmap(m_pix.scaledToHeight(realHeight));
            }
            else
            {
                QLabel::setPixmap(m_pix.scaledToWidth(realWidth));
            }
        }
    }

    double ExtendedLabel::aspectRatio(int w, int h)
    {
        return static_cast<double>(w) / static_cast<double>(h);
    }

    int ExtendedLabel::heightForWidth(int width) const
    {
        if (!m_pix.isNull())
        {
            return static_cast<int>(static_cast<qreal>(m_pix.height()) * width / m_pix.width());
        }
        return QLabel::heightForWidth(width);
    }

    void ExtendedLabel::mousePressEvent(QMouseEvent* /*event*/)
    {
        emit clicked();
    }
} // namespace AzQtComponents

#ifndef MESON_BUILD
#include "Components/moc_ExtendedLabel.cpp"
#endif
