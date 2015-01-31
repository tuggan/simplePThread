/*
 *    Copyright 2015 Dennis Vesterlund
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#include "simpleThread.h"

/*
 * This is a simple implementation of simplified threading.
 * Might well use big parts of this for "real" version but this is mostly a test.
 */

vthread vthread_init(vthread_t id) {
    vthread t = _vthread_alloc();
    t->id = id;
    t->startFunc = NULL;
    t->arg = NULL;
    return t;
}

void vthread_setStartFunc(vthread t, void *(*startFunc) (void*)) {
    t->startFunc = startFunc;
}

void vthread_setArg(vthread t, void * arg) {
    t->arg = arg;
}

int vthread_start(vthread t) {
    if(t == NULL || t->startFunc == NULL)
        return -1;
    return pthread_create(t->id, NULL, t->startFunc, t->arg);
}

vthread vthread_initAndStart(vthread_t id, void *(*startFunc) (void*), void * arg) {
    vthread t = vthread_init(id);
    vthread_setStartFunc(t, startFunc);
    vthread_setArg(t, arg);
    int start = vthread_start(t);
    if(start == 0)
        return t;
    return NULL;
}

vthread _vthread_alloc() {
    return calloc(1, sizeof(struct vthread));
}

void vthread_free(vthread t) {
    free(t);
}

















