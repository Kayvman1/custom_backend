#include "packet_handlers.h"
#include "../packets/packets.h"
#include "../packets/packet_ids.h"
#include <postgresql/libpq-fe.h>

void packet_handlers::test_connection()
{
    PGconn *conn;
    PGresult *res;
    int rec_count;
    int row;
    int col;

    conn = PQconnectdb("dbname=test host=localhost user=kayvan password=Admin");

    if (PQstatus(conn) == CONNECTION_BAD)
    {
        puts("We were unable to connect to the database");
        exit(0);
    }

    else
    {
        puts("GOOD");
    }

    res = PQexec(conn,"SELECT first_name FROM account");

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

    PQfinish(conn);
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