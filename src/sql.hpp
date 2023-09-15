// sql.hpp
#include <userver/storages/postgres/query.hpp>

// ATTENTION: FILE AUTOGENERATED

const storages::postgres::Query kGetGenres{
    R"(SELECT id,
    title
FROM book_shop.genres
ORDER BY id
LIMIT $1
OFFSET $2)",
    userver::storages::postgres::Query::Name{"get_genres"}};

const storages::postgres::Query kGetAuthors{
    R"(SELECT id,
    name::text
FROM book_shop.authors
ORDER BY id 
LIMIT $1
OFFSET $2)",
    userver::storages::postgres::Query::Name{"get_authors"}};

const storages::postgres::Query kUniversalSelector{
    R"(SELECT *
FROM book_shop.$1)",
    userver::storages::postgres::Query::Name{"universal_selector"}};

const storages::postgres::Query kGetAddresses{
    R"(SELECT
id, coordinates::text
FROM 
book_shop.addresses
LIMIT $1
OFFSET $2)",
    userver::storages::postgres::Query::Name{"get_addresses"}};

const storages::postgres::Query kGetEntities{
    R"(SELECT * 
FROM book_shop.$1)",
    userver::storages::postgres::Query::Name{"get_entities"}};

const storages::postgres::Query kUpsertAuthors{
    R"(INSERT INTO book_shop.authors (id, name, bio)
VALUES ($1, $2, $3)
ON CONFLICT (id) DO UPDATE
SET 
    name=EXCLUDED.name,
    bio=EXCLUDED.bio)",
    userver::storages::postgres::Query::Name{"upsert_authors"}};

const storages::postgres::Query kGetSerias{
    R"(SELECT id,
    title
FROM book_shop.serias
ORDER BY id
LIMIT $1 OFFSET $2)",
    userver::storages::postgres::Query::Name{"get_serias"}};

const storages::postgres::Query kGetEmployees{
    R"(SELECT id,
    (SELECT full_name FROM book_shop.people WHERE id = person_id)
FROM book_shop.employees
ORDER BY id
LIMIT $1
OFFSET $2)",
    userver::storages::postgres::Query::Name{"get_employees"}};

const storages::postgres::Query kGetPositions{
    R"(SELECT id,
    (SELECT title FROM book_shop.books WHERE id = book_id )
FROM book_shop.positions
ORDER BY id
LIMIT $1
OFFSET $2)",
    userver::storages::postgres::Query::Name{"get_positions"}};

const storages::postgres::Query kGetOrders{
    R"(SELECT id,
    created_at::text
FROM book_shop.orders
ORDER BY id
LIMIT $1
OFFSET $2)",
    userver::storages::postgres::Query::Name{"get_orders"}};

const storages::postgres::Query kGetCycles{
    R"(SELECT id,
    title
FROM book_shop.cycles
ORDER BY id
LIMIT $1
OFFSET $2)",
    userver::storages::postgres::Query::Name{"get_cycles"}};

const storages::postgres::Query kInsertBooks{
    R"(INSERT INTO TABLE bookshop.books VALUES (123, 234))",
    userver::storages::postgres::Query::Name{"insert_books"}};

// lol, lov it
const storages::postgres::Query kGetSchema{
    R"(WITH glop AS (
  SELECT 
  k.table_name,
  k.column_name
  FROM    information_schema.constraint_column_usage v
  JOIN information_schema.key_column_usage k
  ON k.constraint_name = v.constraint_name
  WHERE k.position_in_unique_constraint IS NULL
)
SELECT 
  isc.table_name table_name,
  isc.column_name column_name, 
  isc.ordinal_position ordinal_position,
  isc.is_nullable::boolean is_nullable,
  isc.data_type data_type,
  (xpath('/row/c/text()', query_to_xml(format('SELECT count(*) AS c FROM %I.%I', 'book_shop', isc.table_name), FALSE, TRUE, '')))[1]::text::integer AS rows_n,
  (glop.column_name IS NOT NULL) is_unique,
  isc.column_name = 'id' is_pk
FROM 
   information_schema.columns isc
LEFT JOIN glop 
ON isc.table_name = glop.table_name AND isc.column_name = glop.column_name
WHERE table_schema = 'book_shop'
ORDER BY table_name, ordinal_position;)",
    userver::storages::postgres::Query::Name{"get_schema"}};

const storages::postgres::Query kGetWarehouses{
    R"(SELECT id,
    name
FROM book_shop.warehouses
ORDER BY id
LIMIT $1 OFFSET $2)",
    userver::storages::postgres::Query::Name{"get_warehouses"}};

const storages::postgres::Query kGetPublishers{
    R"(SELECT id,
    title
FROM book_shop.publishers
ORDER BY id
LIMIT $1
OFFSET $2)",
    userver::storages::postgres::Query::Name{"get_publishers"}};

const storages::postgres::Query kGetCustomers{
    R"(SELECT id,
    (SELECT full_name FROM book_shop.people WHERE id = person_id) 
FROM book_shop.customers
ORDER BY id
LIMIT $1
OFFSET $2)",
    userver::storages::postgres::Query::Name{"get_customers"}};

// simple select
//  double comment
//  book table
const storages::postgres::Query kGetBooks{
    R"(SELECT id,
    title
FROM book_shop.books ORDER BY id
LIMIT $1
OFFSET $2)",
    userver::storages::postgres::Query::Name{"get_books"}};
