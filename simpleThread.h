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

#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>

typedef pthread_t* vthread_t;

// Why vtread?!?! Cus i want to. Fuck you.
struct vthread {
    vthread_t id;
    void *arg;
    void *(*startFunc) (void*);
};

typedef struct vthread *vthread;

/*
 * Proposed interface, by me ofc!
 */

vthread vthread_init(vthread_t id);

void vthread_setStartFunc(vthread t, void *(*startFunc) (void*));

void vthread_setArg(vthread t, void * arg);

int vthread_start(vthread t);

vthread vthread_initAndStart(vthread_t id, void *(*startFunc) (void*), void * arg);

vthread _vthread_alloc();

void vthread_free(vthread t);

















