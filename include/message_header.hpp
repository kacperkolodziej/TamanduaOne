#ifndef TAMANDUAONE_MESSAGE_HEADER_HPP
#define TAMANDUAONE_MESSAGE_HEADER_HPP

#include "config/message_types.hpp"
#include "config/tamanduaone_api.hpp"

namespace tamanduaone {

using tamanduaone::config;

struct TAMANDUAONE_API MessageHeader
{
	MessageId msg_id;
	MessageType type;
	ErrorCode error_code;
	AuthorId author_id;
	GroupId group_id;
	UTCTime utc_time;
	MessageSize size;
	MessageOptions options;
	MessageByte author_name[40];
};

}

#endif
