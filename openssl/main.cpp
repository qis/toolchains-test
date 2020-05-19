#include <gtest/gtest.h>
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

TEST(openssl, crypto) {
  const auto data = OPENSSL_malloc(128);
  ASSERT_NE(data, nullptr);
  OPENSSL_free(data);
}

TEST(openssl, ssl) {
  const auto method = SSLv23_method();
  ASSERT_NE(method, nullptr);
}
