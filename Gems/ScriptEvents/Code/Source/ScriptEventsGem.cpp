/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#include "precompiled.h"

#include "ScriptEventsSystemComponent.h"

#include <AzCore/Memory/SystemAllocator.h>

#include <ScriptEvents/ScriptEventsGem.h>

#include <ScriptEvents/Components/ScriptEventReferencesComponent.h>

namespace ScriptEvents
{
    ScriptEventsModule::ScriptEventsModule()
        : AZ::Module()
        , m_systemImpl(nullptr)
    {
        ScriptEventModuleConfigurationRequestBus::Handler::BusConnect();

        m_descriptors.insert(m_descriptors.end(), {
            ScriptEvents::ScriptEventsSystemComponent::CreateDescriptor(),
            ScriptEvents::Components::ScriptEventReferencesComponent::CreateDescriptor(),
        });
    }

    ScriptEventsSystemComponentImpl* ScriptEventsModule::GetSystemComponentImpl()
    {
        if (!m_systemImpl)
        {
            m_systemImpl = aznew ScriptEventsSystemComponentRuntimeImpl();
        }

        return m_systemImpl;
    }

    /**
    * Add required SystemComponents to the SystemEntity.
    */
    AZ::ComponentTypeList ScriptEventsModule::GetRequiredSystemComponents() const
    {
        return AZ::ComponentTypeList{
            azrtti_typeid<ScriptEvents::ScriptEventsSystemComponent>(),
        };
    }
}

AZ_DECLARE_MODULE_CLASS(Gem_ScriptEvents, ScriptEvents::ScriptEventsModule)
