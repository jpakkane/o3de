/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include <AzQtComponents/Components/Style.h>
#include <AzQtComponents/Components/Widgets/CardHeader.h>
#include <AzQtComponents/Components/Widgets/ColorPicker/ColorController.h>
#include <AzQtComponents/Components/Widgets/ColorPicker/PaletteCard.h>
#include <AzQtComponents/Components/Widgets/ColorPicker/PaletteView.h>
#include <QMenu>
#include <QPushButton>
#include <QVBoxLayout>

namespace AzQtComponents
{
    PaletteCardBase::PaletteCardBase(
        QSharedPointer<Palette> palette, Internal::ColorController* controller, QUndoStack* undoStack, QWidget* parent)
        : QWidget(parent)
        , m_palette(palette)
        , m_header(new CardHeader(this))
        , m_paletteView(new PaletteView(palette.data(), controller, undoStack, this))
    {
        auto mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(0, 0, 0, 0);

        m_header->setExpandable(true);
        mainLayout->addWidget(m_header);

        connect(
            m_paletteView, &PaletteView::selectedColorsChanged, this,
            [controller](const QVector<AZ::Color>& selectedColors)
            {
                if (selectedColors.size() == 1)
                {
                    controller->setColor(selectedColors[0]);
                }
            });

        m_contentsLayout = new QHBoxLayout();

        // NOTE: this is the default set. The actual, user-configurable margins should be
        // set by setContentsMargin() by whatever contains the PaletteCardBase
        const int defaultContentsLeftMargin = 16;
        m_contentsLayout->setContentsMargins(QMargins{ defaultContentsLeftMargin, 0, 0, 0 });

        m_contentsLayout->addWidget(m_paletteView);
        mainLayout->addLayout(m_contentsLayout);

        connect(m_header, &CardHeader::expanderChanged, m_paletteView, &QWidget::setVisible);
        connect(m_header, &CardHeader::contextMenuRequested, this, &PaletteCardBase::contextMenuRequested);
        connect(m_paletteView, &PaletteView::unselectedContextMenuRequested, this, &PaletteCard::contextMenuRequested);
    }

    void PaletteCardBase::setContentsMargins(const QMargins& margins)
    {
        m_contentsLayout->setContentsMargins(margins);
    }

    PaletteCard::PaletteCard(QSharedPointer<Palette> palette, Internal::ColorController* controller, QUndoStack* undoStack, QWidget* parent)
        : PaletteCardBase(palette, controller, undoStack, parent)
    {
        connect(m_paletteView->model(), &QAbstractItemModel::rowsInserted, this, &PaletteCard::handleModelChanged);
        connect(m_paletteView->model(), &QAbstractItemModel::rowsRemoved, this, &PaletteCard::handleModelChanged);
        connect(m_paletteView->model(), &QAbstractItemModel::dataChanged, this, &PaletteCard::handleModelChanged);

        setFocusPolicy(Qt::NoFocus);
    }

    PaletteCard::~PaletteCard()
    {
    }

    void PaletteCard::setTitle(const QString& title)
    {
        if (title == m_title)
        {
            return;
        }

        m_title = title;
        updateHeader();

        emit titleChanged(title);
    }

    QString PaletteCard::title() const
    {
        return m_title;
    }

    bool PaletteCard::modified() const
    {
        return m_modified;
    }

    void PaletteCard::setModified(bool modified)
    {
        if (modified == m_modified)
        {
            return;
        }

        m_modified = modified;
        updateHeader();

        emit modifiedChanged(modified);

        // force style sheet recomputation so the title color changes
        // (polish/unpolish doesn't work as the title label is a child of m_header)
        m_header->setStyleSheet(m_header->styleSheet());
    }

    void PaletteCard::setExpanded(bool expanded)
    {
        m_header->setExpanded(expanded);
    }

    bool PaletteCard::isExpanded() const
    {
        return m_header->isExpanded();
    }

    QSharedPointer<Palette> PaletteCardBase::palette() const
    {
        return m_palette;
    }

    void PaletteCard::handleModelChanged()
    {
        Palette loader;
        QString fileName = QStringLiteral("%1.pal").arg(m_title);
        bool loaded = loader.load(fileName);

        setModified(!loaded || (loaded && loader.colors() != m_palette->colors()));
    }

    void PaletteCard::updateHeader()
    {
        QString headerText = m_title;
        if (m_modified)
        {
            headerText += QStringLiteral("*");
        }

        m_header->setTitle(headerText);
    }

    void PaletteCardBase::setSwatchSize(const QSize& size)
    {
        m_paletteView->setItemSize(size);
    }

    void PaletteCardBase::setGammaEnabled(bool enabled)
    {
        m_paletteView->setGammaEnabled(enabled);
    }

    void PaletteCardBase::setGamma(qreal gamma)
    {
        m_paletteView->setGamma(gamma);
    }

    void PaletteCardBase::tryAdd(const AZ::Color& color)
    {
        m_paletteView->tryAddColor(color);
    }

    bool PaletteCardBase::contains(const AZ::Color& color) const
    {
        return m_paletteView->contains(color);
    }

    QuickPaletteCard::QuickPaletteCard(
        QSharedPointer<Palette> palette, Internal::ColorController* controller, QUndoStack* undoStack, QWidget* parent)
        : PaletteCardBase(palette, controller, undoStack, parent)
    {
        m_paletteView->addDefaultRGBColors();

        m_header->setTitle("Quick Palette");

        connect(m_paletteView, &PaletteView::selectedColorsChanged, this, &QuickPaletteCard::selectedColorsChanged);
    }

} // namespace AzQtComponents

#ifndef MESON_BUILD
#include "Components/Widgets/ColorPicker/moc_PaletteCard.cpp"
#endif
