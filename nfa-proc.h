/*
 * Thompson NFA processor
 *
 * Copyright (c) 2020 Alexei A. Smekalkine <ikle@ikle.ru>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#ifndef NFA_PROC_H
#define NFA_PROC_H  1

#include <stddef.h>

#include "nfa-state.h"

/*
 * The NFA processor constructor captures NFA, no one should try to use
 * the NFA passed to the constructor.
 */
struct nfa_proc *nfa_proc_alloc (struct nfa_state *nfa);
void nfa_proc_free (struct nfa_proc *o);

/*
 * returns 1 on match (stop state reached), zero otherwise
 */
int nfa_proc_start (struct nfa_proc *o);

/*
 * returns -1 on error (no match), node color on match, zero otherwise
 */
int nfa_proc_step  (struct nfa_proc *o, unsigned c);

#endif  /* NFA_PROC_H */
