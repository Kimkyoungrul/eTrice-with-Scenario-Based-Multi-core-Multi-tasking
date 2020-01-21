/**
 *
 * \author Kyoungrul Kim
 */
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _ETSPINLOCK_H_
#define _ETSPINLOCK_H_

typedef unsigned int eteseSpinlockData;

typedef struct eteseSpinlock {
	eteseSpinlockData osData;
	int prior;
} eteseSpinlock;

/**
 * initializes the esespinlock
 * \param self the 'this' pointer of the esespinlock
 */
void eseSpinlock_construct(eteseSpinlock* self);

/**
 * destroys the esespinlock
 * \param self the 'this' pointer of the esespinlock
 */
void eseSpinlock_destruct(eteseSpinlock* self);

/**
 * lock the esespinlock
 * \param self the 'this' pointer of the esespinlock
 */
void eseSpinlock_enter(eteseSpinlock* self);

/**
 * unlock the esespinlock
 * \param self the 'this' pointer of the esespinlock
 */
void eseSpinlock_leave(eteseSpinlock* self);

#endif /* _ETSPINLOCK_H_ */

#ifdef __cplusplus
}
#endif
