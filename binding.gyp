{
  "variables": {
    "v8_is_pre_3_20": "<!(node -pe 'v=process.versions.v8.split(/\./);v[0]>3||v[0]==3&&v[1]>=20?0:1')"
  }
, "targets": [
    {
      "target_name": "get_system_locale_name",
      "defines": [
        "V8_IS_PRE_3_20=<(v8_is_pre_3_20)"
      ]
    , "sources": [
        "src/binding.cc"
      , "src/getSystemLocaleName.cc"
      ]
    }
  ]
}
