{
  "targets": [
    {
      "target_name": "get_system_locale_name"
    , "sources": [
        "src/binding.cc"
      ]
    , "conditions": [
        ['OS=="mac"', {
          "sources": [
            "src/getSystemLocaleName_mac.mm"
          ]
        , 'link_settings': {
            'libraries': [
              '$(SDKROOT)/System/Library/Frameworks/Foundation.framework',
            ],
          }
        }]
      , ['OS!="mac"', {
          "sources": [
            "src/getSystemLocaleName.cc"
          ]
        }]
      ]
    }
  ]
}
