/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include "precompiled.h"
#include "ScriptEventsTestFixture.h"
#include "ScriptEventsTestApplication.h"

namespace ScriptEventsTests
{
    ScriptEventsTests::Application* ScriptEventsTestFixture::s_application = nullptr;
    UnitTest::AllocatorsBase ScriptEventsTestFixture::s_allocatorSetup = {};

    ScriptEventsTests::Application* ScriptEventsTestFixture::GetApplication()
    {
        return s_application;
    }

}

