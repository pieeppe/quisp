/** \file Condition.cc
 *
 *  \authors cldurand
 *  \date 2018/06/25
 *
 *  \brief Condition
 */
#include "Condition.h"
#include <memory>

namespace quisp {
namespace rules {

bool Condition::check(qnicResources *resources) const {
    bool satisfying = true;
    for (auto clause = cbegin(), end = cend(); clause != end; clause++){
        if (!(*clause)->check(resources)){
            satisfying = false;
            break;
        }
    }
    return satisfying;
}

bool Condition::checkTerminate(qnicResources *resources) const {
    bool satisfying = true;
    for (auto clause = cbegin(), end = cend(); clause != end; clause++){
        if (!(*clause)->checkTerminate(resources)){
            satisfying = false;
            break;
        }
    }
    return satisfying;
}


} // namespace rules
} // namespace quisp
