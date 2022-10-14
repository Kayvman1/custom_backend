# CMake generated Testfile for 
# Source directory: /home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/test
# Build directory: /home/kayvan/Repos/custom_backend/build/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(driver "test_driver")
set_tests_properties(driver PROPERTIES  ENVIRONMENT "ENCRYPTION_TESTS_PATH=/home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/../../data/client_side_encryption")
add_test(logging "test_logging")
add_test(instance "test_instance")
add_test(crud_specs "test_crud_specs")
set_tests_properties(crud_specs PROPERTIES  ENVIRONMENT "CRUD_LEGACY_TESTS_PATH=/home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/../../data/crud/legacy")
add_test(gridfs_specs "test_gridfs_specs")
set_tests_properties(gridfs_specs PROPERTIES  ENVIRONMENT "GRIDFS_TESTS_PATH=/home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/../../data/gridfs")
add_test(client_side_encryption_specs "test_client_side_encryption_specs")
set_tests_properties(client_side_encryption_specs PROPERTIES  ENVIRONMENT "ENCRYPTION_TESTS_PATH=/home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/../../data/client_side_encryption")
add_test(command_monitoring_specs "test_command_monitoring_specs")
set_tests_properties(command_monitoring_specs PROPERTIES  ENVIRONMENT "COMMAND_MONITORING_TESTS_PATH=/home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/../../data/command-monitoring")
add_test(transactions_specs "test_transactions_specs")
set_tests_properties(transactions_specs PROPERTIES  ENVIRONMENT "TRANSACTIONS_TESTS_PATH=/home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/../../data/transactions;WITH_TRANSACTION_TESTS_PATH=/home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/../../data/with_transaction")
add_test(retryable_reads_spec "test_retryable_reads_specs")
set_tests_properties(retryable_reads_spec PROPERTIES  ENVIRONMENT "RETRYABLE_READS_TESTS_PATH=/home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/../../data/retryable-reads")
add_test(read_write_concern_specs "test_read_write_concern_specs")
set_tests_properties(read_write_concern_specs PROPERTIES  ENVIRONMENT "READ_WRITE_CONCERN_OPERATION_TESTS_PATH=/home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/../../data/read-write-concern/operation")
add_test(unified_format_spec "test_unified_format_spec")
set_tests_properties(unified_format_spec PROPERTIES  ENVIRONMENT "CHANGE_STREAMS_UNIFIED_TESTS_PATH=/home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/../../data/change-streams/unified;COLLECTION_MANAGEMENT_TESTS_PATH=/home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/../../data/collection-management;CRUD_UNIFIED_TESTS_PATH=/home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/../../data/crud/unified;SESSION_UNIFIED_TESTS_PATH=/home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/../../data/sessions/unified/;UNIFIED_FORMAT_TESTS_PATH=/home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/../../data/unified-format;VERSIONED_API_TESTS_PATH=/home/kayvan/Repos/custom_backend/lib/mongo-cxx-driver-r3.7.0/src/mongocxx/../../data/versioned-api")
add_test(versioned_api "test_versioned_api")
