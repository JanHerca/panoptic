//  Copyright (C) 2005-2012 Robert Kooima
//
//  THUMB is free software; you can redistribute it and/or modify it under
//  the terms of  the GNU General Public License as  published by the Free
//  Software  Foundation;  either version 2  of the  License,  or (at your
//  option) any later version.
//
//  This program  is distributed in the  hope that it will  be useful, but
//  WITHOUT   ANY  WARRANTY;   without  even   the  implied   warranty  of
//  MERCHANTABILITY  or FITNESS  FOR A  PARTICULAR PURPOSE.   See  the GNU
//  General Public License for more details.

#include "scm-frame.hpp"

//------------------------------------------------------------------------------

scm_frame::scm_frame()
{
}

//------------------------------------------------------------------------------

void scm_frame::bind(int channel, GLuint program) const
{
    GLenum unit = 0;

    glUseProgram(program);

    for (scm_image_c i = images.begin(); i != images.end(); ++i)
        if ((*i)->is_channel(channel))
            (*i)->bind(program, unit++);

    glActiveTexture(GL_TEXTURE0);

    // glUniform1f(u_r0, GLfloat(cache.get_r0()));
    // glUniform1f(u_r1, GLfloat(cache.get_r1()));
}

void scm_frame::free(int channel) const
{
    GLenum unit = 0;

    glUseProgram(0);

    for (scm_image_c i = images.begin(); i != images.end(); ++i)
        if ((*i)->is_channel(channel))
            (*i)->free(unit++);

    glActiveTexture(GL_TEXTURE0);
}

//------------------------------------------------------------------------------

void scm_frame::set(GLuint program, int d, int t, long long i) const
{
}

void scm_frame::clr(GLuint program, int d) const
{
}

//------------------------------------------------------------------------------

// Return true if any one of the images has page i in cache.

bool scm_frame::page_status(long long i) const
{
    return false;
}

double scm_frame::page_r0(long long i) const
{
    return 1.0;
}

double scm_frame::page_r1(long long i) const
{
    return 1.0;
}

void scm_frame::page_touch(long long i, int time)
{
}

//------------------------------------------------------------------------------

double scm_frame::get_r0() const
{
    return 1.0;
}

double scm_frame::get_r1() const
{
    return 1.0;
}

//------------------------------------------------------------------------------
