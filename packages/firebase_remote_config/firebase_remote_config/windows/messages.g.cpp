// Copyright 2025, the Chromium project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.
// Autogenerated from Pigeon (v25.3.2), do not edit directly.
// See also: https://pub.dev/packages/pigeon

#undef _HAS_EXCEPTIONS

#include "messages.g.h"

#include <flutter/basic_message_channel.h>
#include <flutter/binary_messenger.h>
#include <flutter/encodable_value.h>
#include <flutter/standard_message_codec.h>

#include <map>
#include <optional>
#include <string>

namespace firebase_remote_config_windows {
using flutter::BasicMessageChannel;
using flutter::CustomEncodableValue;
using flutter::EncodableList;
using flutter::EncodableMap;
using flutter::EncodableValue;

FlutterError CreateConnectionError(const std::string channel_name) {
  return FlutterError(
      "channel-error",
      "Unable to establish connection on channel: '" + channel_name + "'.",
      EncodableValue(""));
}

// RemoteConfigPigeonSettings

RemoteConfigPigeonSettings::RemoteConfigPigeonSettings(
    int64_t fetch_timeout_seconds, int64_t minimum_fetch_interval_seconds)
    : fetch_timeout_seconds_(fetch_timeout_seconds),
      minimum_fetch_interval_seconds_(minimum_fetch_interval_seconds) {}

int64_t RemoteConfigPigeonSettings::fetch_timeout_seconds() const {
  return fetch_timeout_seconds_;
}

void RemoteConfigPigeonSettings::set_fetch_timeout_seconds(int64_t value_arg) {
  fetch_timeout_seconds_ = value_arg;
}

int64_t RemoteConfigPigeonSettings::minimum_fetch_interval_seconds() const {
  return minimum_fetch_interval_seconds_;
}

void RemoteConfigPigeonSettings::set_minimum_fetch_interval_seconds(
    int64_t value_arg) {
  minimum_fetch_interval_seconds_ = value_arg;
}

EncodableList RemoteConfigPigeonSettings::ToEncodableList() const {
  EncodableList list;
  list.reserve(2);
  list.push_back(EncodableValue(fetch_timeout_seconds_));
  list.push_back(EncodableValue(minimum_fetch_interval_seconds_));
  return list;
}

RemoteConfigPigeonSettings RemoteConfigPigeonSettings::FromEncodableList(
    const EncodableList& list) {
  RemoteConfigPigeonSettings decoded(std::get<int64_t>(list[0]),
                                     std::get<int64_t>(list[1]));
  return decoded;
}

PigeonInternalCodecSerializer::PigeonInternalCodecSerializer() {}

EncodableValue PigeonInternalCodecSerializer::ReadValueOfType(
    uint8_t type, flutter::ByteStreamReader* stream) const {
  switch (type) {
    case 129: {
      return CustomEncodableValue(RemoteConfigPigeonSettings::FromEncodableList(
          std::get<EncodableList>(ReadValue(stream))));
    }
    default:
      return flutter::StandardCodecSerializer::ReadValueOfType(type, stream);
  }
}

void PigeonInternalCodecSerializer::WriteValue(
    const EncodableValue& value, flutter::ByteStreamWriter* stream) const {
  if (const CustomEncodableValue* custom_value =
          std::get_if<CustomEncodableValue>(&value)) {
    if (custom_value->type() == typeid(RemoteConfigPigeonSettings)) {
      stream->WriteByte(129);
      WriteValue(EncodableValue(
                     std::any_cast<RemoteConfigPigeonSettings>(*custom_value)
                         .ToEncodableList()),
                 stream);
      return;
    }
  }
  flutter::StandardCodecSerializer::WriteValue(value, stream);
}

/// The codec used by FirebaseRemoteConfigHostApi.
const flutter::StandardMessageCodec& FirebaseRemoteConfigHostApi::GetCodec() {
  return flutter::StandardMessageCodec::GetInstance(
      &PigeonInternalCodecSerializer::GetInstance());
}

// Sets up an instance of `FirebaseRemoteConfigHostApi` to handle messages
// through the `binary_messenger`.
void FirebaseRemoteConfigHostApi::SetUp(
    flutter::BinaryMessenger* binary_messenger,
    FirebaseRemoteConfigHostApi* api) {
  FirebaseRemoteConfigHostApi::SetUp(binary_messenger, api, "");
}

void FirebaseRemoteConfigHostApi::SetUp(
    flutter::BinaryMessenger* binary_messenger,
    FirebaseRemoteConfigHostApi* api,
    const std::string& message_channel_suffix) {
  const std::string prepended_suffix =
      message_channel_suffix.length() > 0
          ? std::string(".") + message_channel_suffix
          : "";
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.firebase_remote_config_platform_interface."
        "FirebaseRemoteConfigHostApi.fetch" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_app_name_arg = args.at(0);
              if (encodable_app_name_arg.IsNull()) {
                reply(WrapError("app_name_arg unexpectedly null."));
                return;
              }
              const auto& app_name_arg =
                  std::get<std::string>(encodable_app_name_arg);
              api->Fetch(app_name_arg,
                         [reply](std::optional<FlutterError>&& output) {
                           if (output.has_value()) {
                             reply(WrapError(output.value()));
                             return;
                           }
                           EncodableList wrapped;
                           wrapped.push_back(EncodableValue());
                           reply(EncodableValue(std::move(wrapped)));
                         });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.firebase_remote_config_platform_interface."
        "FirebaseRemoteConfigHostApi.fetchAndActivate" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_app_name_arg = args.at(0);
              if (encodable_app_name_arg.IsNull()) {
                reply(WrapError("app_name_arg unexpectedly null."));
                return;
              }
              const auto& app_name_arg =
                  std::get<std::string>(encodable_app_name_arg);
              api->FetchAndActivate(
                  app_name_arg, [reply](ErrorOr<bool>&& output) {
                    if (output.has_error()) {
                      reply(WrapError(output.error()));
                      return;
                    }
                    EncodableList wrapped;
                    wrapped.push_back(
                        EncodableValue(std::move(output).TakeValue()));
                    reply(EncodableValue(std::move(wrapped)));
                  });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.firebase_remote_config_platform_interface."
        "FirebaseRemoteConfigHostApi.activate" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_app_name_arg = args.at(0);
              if (encodable_app_name_arg.IsNull()) {
                reply(WrapError("app_name_arg unexpectedly null."));
                return;
              }
              const auto& app_name_arg =
                  std::get<std::string>(encodable_app_name_arg);
              api->Activate(app_name_arg, [reply](ErrorOr<bool>&& output) {
                if (output.has_error()) {
                  reply(WrapError(output.error()));
                  return;
                }
                EncodableList wrapped;
                wrapped.push_back(
                    EncodableValue(std::move(output).TakeValue()));
                reply(EncodableValue(std::move(wrapped)));
              });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.firebase_remote_config_platform_interface."
        "FirebaseRemoteConfigHostApi.setConfigSettings" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_app_name_arg = args.at(0);
              if (encodable_app_name_arg.IsNull()) {
                reply(WrapError("app_name_arg unexpectedly null."));
                return;
              }
              const auto& app_name_arg =
                  std::get<std::string>(encodable_app_name_arg);
              const auto& encodable_settings_arg = args.at(1);
              if (encodable_settings_arg.IsNull()) {
                reply(WrapError("settings_arg unexpectedly null."));
                return;
              }
              const auto& settings_arg =
                  std::any_cast<const RemoteConfigPigeonSettings&>(
                      std::get<CustomEncodableValue>(encodable_settings_arg));
              api->SetConfigSettings(
                  app_name_arg, settings_arg,
                  [reply](std::optional<FlutterError>&& output) {
                    if (output.has_value()) {
                      reply(WrapError(output.value()));
                      return;
                    }
                    EncodableList wrapped;
                    wrapped.push_back(EncodableValue());
                    reply(EncodableValue(std::move(wrapped)));
                  });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.firebase_remote_config_platform_interface."
        "FirebaseRemoteConfigHostApi.setDefaults" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_app_name_arg = args.at(0);
              if (encodable_app_name_arg.IsNull()) {
                reply(WrapError("app_name_arg unexpectedly null."));
                return;
              }
              const auto& app_name_arg =
                  std::get<std::string>(encodable_app_name_arg);
              const auto& encodable_default_parameters_arg = args.at(1);
              if (encodable_default_parameters_arg.IsNull()) {
                reply(WrapError("default_parameters_arg unexpectedly null."));
                return;
              }
              const auto& default_parameters_arg =
                  std::get<EncodableMap>(encodable_default_parameters_arg);
              api->SetDefaults(app_name_arg, default_parameters_arg,
                               [reply](std::optional<FlutterError>&& output) {
                                 if (output.has_value()) {
                                   reply(WrapError(output.value()));
                                   return;
                                 }
                                 EncodableList wrapped;
                                 wrapped.push_back(EncodableValue());
                                 reply(EncodableValue(std::move(wrapped)));
                               });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.firebase_remote_config_platform_interface."
        "FirebaseRemoteConfigHostApi.ensureInitialized" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_app_name_arg = args.at(0);
              if (encodable_app_name_arg.IsNull()) {
                reply(WrapError("app_name_arg unexpectedly null."));
                return;
              }
              const auto& app_name_arg =
                  std::get<std::string>(encodable_app_name_arg);
              api->EnsureInitialized(
                  app_name_arg, [reply](std::optional<FlutterError>&& output) {
                    if (output.has_value()) {
                      reply(WrapError(output.value()));
                      return;
                    }
                    EncodableList wrapped;
                    wrapped.push_back(EncodableValue());
                    reply(EncodableValue(std::move(wrapped)));
                  });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.firebase_remote_config_platform_interface."
        "FirebaseRemoteConfigHostApi.setCustomSignals" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_app_name_arg = args.at(0);
              if (encodable_app_name_arg.IsNull()) {
                reply(WrapError("app_name_arg unexpectedly null."));
                return;
              }
              const auto& app_name_arg =
                  std::get<std::string>(encodable_app_name_arg);
              const auto& encodable_custom_signals_arg = args.at(1);
              if (encodable_custom_signals_arg.IsNull()) {
                reply(WrapError("custom_signals_arg unexpectedly null."));
                return;
              }
              const auto& custom_signals_arg =
                  std::get<EncodableMap>(encodable_custom_signals_arg);
              api->SetCustomSignals(
                  app_name_arg, custom_signals_arg,
                  [reply](std::optional<FlutterError>&& output) {
                    if (output.has_value()) {
                      reply(WrapError(output.value()));
                      return;
                    }
                    EncodableList wrapped;
                    wrapped.push_back(EncodableValue());
                    reply(EncodableValue(std::move(wrapped)));
                  });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.firebase_remote_config_platform_interface."
        "FirebaseRemoteConfigHostApi.getAll" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_app_name_arg = args.at(0);
              if (encodable_app_name_arg.IsNull()) {
                reply(WrapError("app_name_arg unexpectedly null."));
                return;
              }
              const auto& app_name_arg =
                  std::get<std::string>(encodable_app_name_arg);
              api->GetAll(app_name_arg,
                          [reply](ErrorOr<EncodableMap>&& output) {
                            if (output.has_error()) {
                              reply(WrapError(output.error()));
                              return;
                            }
                            EncodableList wrapped;
                            wrapped.push_back(
                                EncodableValue(std::move(output).TakeValue()));
                            reply(EncodableValue(std::move(wrapped)));
                          });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
  {
    BasicMessageChannel<> channel(
        binary_messenger,
        "dev.flutter.pigeon.firebase_remote_config_platform_interface."
        "FirebaseRemoteConfigHostApi.getProperties" +
            prepended_suffix,
        &GetCodec());
    if (api != nullptr) {
      channel.SetMessageHandler(
          [api](const EncodableValue& message,
                const flutter::MessageReply<EncodableValue>& reply) {
            try {
              const auto& args = std::get<EncodableList>(message);
              const auto& encodable_app_name_arg = args.at(0);
              if (encodable_app_name_arg.IsNull()) {
                reply(WrapError("app_name_arg unexpectedly null."));
                return;
              }
              const auto& app_name_arg =
                  std::get<std::string>(encodable_app_name_arg);
              api->GetProperties(
                  app_name_arg, [reply](ErrorOr<EncodableMap>&& output) {
                    if (output.has_error()) {
                      reply(WrapError(output.error()));
                      return;
                    }
                    EncodableList wrapped;
                    wrapped.push_back(
                        EncodableValue(std::move(output).TakeValue()));
                    reply(EncodableValue(std::move(wrapped)));
                  });
            } catch (const std::exception& exception) {
              reply(WrapError(exception.what()));
            }
          });
    } else {
      channel.SetMessageHandler(nullptr);
    }
  }
}

EncodableValue FirebaseRemoteConfigHostApi::WrapError(
    std::string_view error_message) {
  return EncodableValue(
      EncodableList{EncodableValue(std::string(error_message)),
                    EncodableValue("Error"), EncodableValue()});
}

EncodableValue FirebaseRemoteConfigHostApi::WrapError(
    const FlutterError& error) {
  return EncodableValue(EncodableList{EncodableValue(error.code()),
                                      EncodableValue(error.message()),
                                      error.details()});
}

}  // namespace firebase_remote_config_windows
