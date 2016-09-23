#include "event_loop.h"
#include "event_loop_impl.h"

namespace boson {

event_loop::~event_loop() {
}

event_loop::event_loop(event_handler& handler) : loop_impl_{new event_loop_impl{handler}} {
}

int event_loop::register_event(void* data) {
  return loop_impl_->register_event(data);
}

void event_loop::send_event(int event) {
  loop_impl_->send_event(event);
}

int event_loop::register_read(int fd, void* data) {
  return loop_impl_->register_read(fd, data);
}

int event_loop::register_write(int fd, void* data) {
  return loop_impl_->register_write(fd, data);
}

void event_loop::disable(int event_id) {
  loop_impl_->disable(event_id);
}

void event_loop::enable(int event_id) {
  loop_impl_->disable(event_id);
}

void* event_loop::unregister(int event_id) {
  return loop_impl_->unregister(event_id);
}

loop_end_reason event_loop::loop(int max_iter, int timeout_ms) {
  return loop_impl_->loop(max_iter, timeout_ms);
}

}  // namespace boson
