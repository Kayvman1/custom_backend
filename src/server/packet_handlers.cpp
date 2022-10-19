#include "packet_handlers.h"
#include "../packets/packets.h"
#include "../packets/packet_ids.h"
#include "server.h"

#include <sw/redis++/redis++.h>
// # include <iostream>
using namespace sw::redis;

void packet_handlers::login_request_handler(server *s, uint8_t *raw_msg, virtual_socket *vs)
{
    auto redis = Redis("tcp://127.0.0.1:6379");
    std::cout << redis.ping() << std::endl;
}

void packet_handlers::test_request_handler(server *s, uint8_t *raw_msg, virtual_socket *vs)
{
    test_request *req = new test_request();
    test_response *resp = new test_response();
    uint8_t *buf = (uint8_t *)std::malloc(500);
    test_request::unpack(req, raw_msg);
    resp->val = req->val;

    packet *p = new packet();
    p->message_type = TEST_PACKET;
    p->message_id = TEST_PACKET_IDS::test_response_id;
    size_t packet_size = packet::pack(p, buf, resp);
    vs->write(virtual_fd::CLIENT, buf, packet_size);

    return;
}

void packet_handlers::response_handler(server *s, uint8_t *raw_msg, virtual_socket *vs)
{
    return;
}