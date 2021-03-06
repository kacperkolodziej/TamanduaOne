#ifndef TAMANDUA_MESSAGE_MANAGER_HPP
#define TAMANDUA_MESSAGE_MANAGER_HPP

#include <deque>
#include <thread>
#include <mutex>
#include <utility>
#include <condition_variable>
#include <memory>

#include "config/tamandua_api.hpp"
#include "config/message_types.hpp"

namespace tamandua {
	
class Server;
class Message;
class Participant;

class TAMANDUA_API MessageManager
{
typedef std::deque<std::pair<std::shared_ptr<Participant>, Message>> MessagesQueue;
private:
	Server& server_;
	MessagesQueue process_queue_;
	std::thread processing_thread_;
	std::mutex process_queue_lock_;
	std::condition_variable process_cv_;

	MessagesQueue send_queue_;
	std::thread sending_thread_;
	std::mutex send_queue_lock_;
	std::condition_variable send_cv_;

	config::MessageId last_message_id_;
	bool processing_thread_run_;
	bool sending_thread_run_;

public:
	MessageManager(Server&);
	~MessageManager();
	MessageManager(const MessageManager&) = delete;

	Server& server();
	void processMessage(std::shared_ptr<Participant>, Message&);
	void sendMessage(std::shared_ptr<Participant>, Message&);

	void processingThread();
	void sendingThread();

private:
	config::MessageId nextMessageId_();
	void fillHeader_(Message&);
	
};

} // namespace tamandua

#endif
