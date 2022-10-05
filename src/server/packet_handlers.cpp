#include "packet_handlers.h"
#include "../packets/packets.h"
#include "../packets/packet_ids.h"
#include <postgresql/libpq-fe.h>
#include "server.cpp"

void packet_handlers::login_request_handler(uint8_t *raw_msg, virtual_socket *vs)
{
    int rec_count;
    int row;
    int col;
    PGresult *res;
    
    login_request *req = (login_request *)raw_msg;
    std::string query = "SELECT * FROM account WHERE username = '" + req->username + "' AND password =" + req->password;
    res = PQexec(client::conn, query.c_str());

    if (PQresultStatus(res) != PGRES_TUPLES_OK)
    {
        puts("We did not get any data!");
        return;
    }

    rec_count = PQntuples(res);

    printf("We received %d records.\n", rec_count);
    puts("==========================");

    for (row = 0; row < rec_count; row++)
    {
        for (col = 0; col < 1; col++)
        {
            printf("%s\t", PQgetvalue(res, row, col));
        }
        puts("");
    }

    puts("==========================");

    PQclear(res);

    PQfinish(client::conn);
}

void packet_handlers::test_request_handler(uint8_t *raw_msg, virtual_socket *vs)
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

void packet_handlers::response_handler(uint8_t *raw_msg, virtual_socket *vs)
{
    return;
}