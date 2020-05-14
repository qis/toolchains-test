#include <catch.hpp>
#include <openssl/crypto.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <string>

const auto g_init = []() {
  SSL_library_init();
  SSL_load_error_strings();
  OpenSSL_add_all_ciphers();
  OpenSSL_add_all_digests();
  OpenSSL_add_all_algorithms();
  ERR_load_crypto_strings();
  return true;
}();

TEST_CASE("openssl::crypto") {
  const auto data = OPENSSL_malloc(128);
  REQUIRE(data != nullptr);
  OPENSSL_free(data);
}

TEST_CASE("openssl::ssl") {
  const auto method = SSLv23_method();
  REQUIRE(method != nullptr);
}
