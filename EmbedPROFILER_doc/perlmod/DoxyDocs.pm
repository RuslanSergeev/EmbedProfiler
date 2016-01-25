$doxydocs=
{
  classes => [
    {
      name => 'My_class',
      all_members => [
        {
          name => 'I',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'My_class'
        },
        {
          name => 'Increment_I',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'My_class'
        },
        {
          name => 'My_class',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'My_class'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'My_class',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'Increment_I',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'I',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'volatile float'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'My_struct',
      all_members => [
        {
          name => 'I',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'My_struct'
        }
      ],
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'I',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'volatile float'
          }
        ]
      },
      brief => {},
      detailed => {}
    }
  ],
  namespaces => [
  ],
  files => [
    {
      name => 'profiler_example.cpp',
      includes => [
        {
          name => 'stdio.h'
        },
        {
          name => 'time.h'
        },
        {
          name => 'PROFILING_tools.h',
          ref => '_p_r_o_f_i_l_i_n_g__tools_8h'
        }
      ],
      included_by => [
      ],
      typedefs => {
        members => [
          {
            kind => 'typedef',
            name => 'My_struct',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'struct My_struct'
          }
        ]
      },
      functions => {
        members => [
          {
            kind => 'function',
            name => '__attribute__',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => '(always_inline)'
              }
            ]
          },
          {
            kind => 'function',
            name => 'main',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'argc',
                type => 'int'
              },
              {
                declaration_name => 'argv',
                type => 'char *',
                array => '[]'
              }
            ]
          }
        ]
      },
      variables => {
        members => [
          {
            kind => 'variable',
            name => 'obj',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'My_class'
          },
          {
            kind => 'variable',
            name => 'str',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'My_struct'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'PROFILING_tools.c',
      includes => [
        {
          name => 'PROFILING_tools.h',
          ref => '_p_r_o_f_i_l_i_n_g__tools_8h'
        }
      ],
      included_by => [
      ],
      functions => {
        members => [
          {
            kind => 'function',
            name => 'PROFILER_timestamp_diff_to_float',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static float',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'PROFILER_instance_index',
                type => 'int32_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'PROFILER_calculate_all_profiles_average',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static float',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'PROFILER_get_current_profile_average',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static float',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'PROFILER_instance_index',
                type => 'int32_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'PROFILER_log_instance',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'PROFILER_instance_index',
                type => 'uint16_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'PROFILER_log',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Вывести отчёт о работе профилировщика.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Сообщает затраченное на работу каждого профилировщика время, имена файлов, номера строк, названия функций где был создан данный профилировщик. Также сообщает число вызовов данного профилировщика.'
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      variables => {
        members => [
          {
            kind => 'variable',
            name => 'PROFILER_instance_last_index',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Индекс последнего инициализированного профилировщика.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Инициализирован значением PROFILER_INSTANCE_NOT_INITIALIZED, поскольку в начальный момент ни один профилировщик ещё не инициализирован.'
                }
              ]
            },
            type => 'int32_t',
            initializer => ' PROFILER_INSTANCE_NOT_INITIALIZED'
          },
          {
            kind => 'variable',
            name => 'PROFILER_files_names',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const char *',
            initializer => ' {0}'
          },
          {
            kind => 'variable',
            name => 'PROFILER_procedures_names',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const char *',
            initializer => ' {0}'
          },
          {
            kind => 'variable',
            name => 'PROFILER_lines_numbers',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint32_t',
            initializer => ' {0}'
          },
          {
            kind => 'variable',
            name => 'PROFILER_times_called',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint32_t',
            initializer => ' {0}'
          },
          {
            kind => 'variable',
            name => 'PROFILER_total_times',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'PROFILER_timestruct',
            initializer => ' {0}'
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'text',
            content => 'Файл '
          },
          {
            type => 'url',
            link => '_p_r_o_f_i_l_i_n_g__tools_8c',
            content => 'PROFILING_tools.c'
          },
          {
            type => 'text',
            content => ' является частью библиотеки EmbedPROFILER - библиотеки профилировщика времени вызовов.'
          }
        ]
      },
      detailed => {
        doc => [
          {
            author => [
              {
                type => 'text',
                content => 'Sergeev Ruslan. OOO SPUTNIX, MIPT High-Precision Attitude Control Systems Laboratory '
              }
            ]
          },
          {
            version => [
              {
                type => 'text',
                content => 'V1.0.0 '
              }
            ]
          },
          {
            date => [
              {
                type => 'text',
                content => '23-January-2016 Профилировщик времени вызовов - средство анализа исходного кода программ, представляющее программистам и инженерам анализировать время, затраченное на выполнение того или иного участка кода в процентном соотношении (относительно общего времени работы профилировщика).'
              }
            ]
          },
          {
            attention => [
              {
                type => 'text',
                content => 'THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME. AS A RESULT, OOO SPUTNIX, MIPT High-Precision Attitude Control Systems Laboratory SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.'
              }
            ]
          },
          {
            type => 'style',
            style => 'center',
            enable => 'yes'
          },
          {
            type => 'symbol',
            symbol => 'copyright'
          },
          {
            type => 'text',
            content => ' COPYRIGHT 2016 RUSLAN SERGEEV'
          },
          {
            type => 'style',
            style => 'center',
            enable => 'no'
          }
        ]
      }
    },
    {
      name => 'PROFILING_tools.h',
      includes => [
        {
          name => 'stdio.h'
        },
        {
          name => 'stdint.h'
        },
        {
          name => 'time.h'
        }
      ],
      included_by => [
        {
          name => 'profiler_example.cpp',
          ref => 'profiler__example_8cpp'
        },
        {
          name => 'PROFILING_tools.c',
          ref => '_p_r_o_f_i_l_i_n_g__tools_8c'
        }
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'PROFILER_TOTAL_PROFILERS',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Максимальное число работающих профилировщиков времени вызова.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Это число определяет размеры массивов для хранения указателей на названия функций, имена файлов, номера строк и число вызовов.'
                }
              ]
            },
            initializer => '1024'
          },
          {
            kind => 'define',
            name => 'PROFILER_GLOBAL_PROFILE_INDEX',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Индекс "глобального профиллировщика" - начального и главного профилировщика времени вызовов.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Этот профилировщик должен быть вызван в начале работы с системой профилирования времени вызовов. Измеренное глобальным профилировщиком время будет считаться временем работы системы. Проценты потреблённого времени, рассчитанные остальными профилировщиками представляют собой отношение времени работы конкретного профилировщика к времени работы глобального профилировщика: '
                },
                {
                  type => 'formula',
                  id => '',
                  content => '\\[ average[i] = \\frac{PROFILER\\_total\\_times[i]}{PROFILER\\_total\\_times[0]} \\]'
                }
              ]
            },
            initializer => '0'
          },
          {
            kind => 'define',
            name => 'PROFILER_LOCAL_PROFILES_BEGIN',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Начальный индекс локальных профилировщиков.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'С данного индекса будут следовать локальные профилировщики - замеряющие время выполнения конкретного локального вызова.'
                }
              ]
            },
            initializer => '((PROFILER_GLOBAL_PROFILE_INDEX)+1)'
          },
          {
            kind => 'define',
            name => 'PROFILER_INSTANCE_NOT_INITIALIZED',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Определяет неинициализированный индекс.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Используется для определения того является ли данный профилировщик инициализированным или он был вызван впервые и его ещё необходимо инициализировать.'
                }
              ]
            },
            initializer => '-1'
          },
          {
            kind => 'define',
            name => 'PROFILER_local_start',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Начинает/продолжает профилировку секции исходного кода.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Если профилировщик начинает работу впервые, то происходит запись текущего местоположения в соответствующие массивы. Запоминается текущее время.'
                }
              ]
            },
            parameters => [
            ],
            initializer => '{\\
		static int32_t PROFILER_instance_index = PROFILER_INSTANCE_NOT_INITIALIZED;\\
		PROFILER_timestruct PROFILER_begin_time, PROFILER_end_time;\\
		if(PROFILER_instance_is_not_initialized(PROFILER_instance_index)){\\
            PROFILER_instance_index = PROFILER_get_free_instance_index();\\
            PROFILER_instance_init(__FILE__, __FUNCTION__, __LINE__, PROFILER_instance_index);\\
		}\\
        PROFILER_refresh_times_called(PROFILER_instance_index);\\
        PROFILER_get_current_time(&PROFILER_begin_time);'
          },
          {
            kind => 'define',
            name => 'PROFILER_local_stop',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Окончание работы/вызова локального профилировщика.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Запоминается время окончания работы/вызова профилировщика. Это время, как и время начала работы/вызова профилировщика используется для обновления общего затраченного времени. Общее затраченное профилировщиком время используется системой профилировки для оценки загруженности профилируемой секции кода.'
                }
              ]
            },
            parameters => [
            ],
            initializer => 'PROFILER_get_current_time(&PROFILER_end_time);\\
            PROFILER_refresh_time_consumed(PROFILER_begin_time, PROFILER_end_time, PROFILER_instance_index);\\
    }'
          },
          {
            kind => 'define',
            name => 'PROFILER_global_stop',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Окончание работы глобального профилировщика.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Запоминается время окончания работы системы профилирования. Которое используется в дальнейшем для расчёта времени работы системы профилирования.Добавлено в портируемый раздел, поскольку завершение работы профилировщика может быть платформо-зависимой.'
                }
              ]
            },
            parameters => [
            ],
            initializer => 'PROFILER_local_stop()'
          }
        ]
      },
      typedefs => {
        members => [
          {
            kind => 'typedef',
            name => 'PROFILER_timestruct',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Тип переменной для хранения измерений времени.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Для оптимальной работы не рекомендуется хранение времени в целочисленных типах.'
                }
              ]
            },
            type => 'struct timespec'
          }
        ]
      },
      functions => {
        members => [
          {
            kind => 'function',
            name => '__attribute__',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {},
            detailed => {},
            type => 'static',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => '(always_inline)'
              }
            ]
          },
          {
            kind => 'function',
            name => 'PROFILER_log',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Вывести отчёт о работе профилировщика.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Сообщает затраченное на работу каждого профилировщика время, имена файлов, номера строк, названия функций где был создан данный профилировщик. Также сообщает число вызовов данного профилировщика.'
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'PROFILER_get_current_time',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Получить текущее время в системе.'
                }
              ]
            },
            detailed => {
              doc => [
                params => [
                  {
                    parameters => [
                      {
                        name => 'PROFILER_timestruct'
                      }
                    ],
                    doc => [
                      {
                        type => 'text',
                        content => '*PROFILER_timestruct_instance '
                      },
                      {
                        type => 'linebreak'
                      },
                      {
                        type => 'text',
                        content => ' Указатель на структуру, в которой будет сохранено системное время.'
                      }
                    ]
                  }
                ]
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'PROFILER_timestruct_instance',
                type => 'PROFILER_timestruct *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'PROFILER_refresh_time_consumed',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Обновить общее время затраченное на работу указанного профилировщика за все его вызовы.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Добавляет время потраченное указанным профилировщиком за последний вызов к общему времени за все вызовы, затраченному указанным профилировщиком. '
                },
                params => [
                  {
                    parameters => [
                      {
                        name => 'PROFILER_timestruct'
                      }
                    ],
                    doc => [
                      {
                        type => 'text',
                        content => 'PROFILER_begin_time '
                      },
                      {
                        type => 'linebreak'
                      },
                      {
                        type => 'text',
                        content => ' Время начала работы (очередного вызова) локального профилировщика. '
                      }
                    ]
                  },
                  {
                    parameters => [
                      {
                        name => 'PROFILER_timestruct'
                      }
                    ],
                    doc => [
                      {
                        type => 'parbreak'
                      },
                      {
                        type => 'text',
                        content => 'PROFILER_end_time '
                      },
                      {
                        type => 'linebreak'
                      },
                      {
                        type => 'text',
                        content => ' Время окончания работы (очередного завершения) локального профилировщика. '
                      }
                    ]
                  },
                  {
                    parameters => [
                      {
                        name => 'int32_t'
                      }
                    ],
                    doc => [
                      {
                        type => 'parbreak'
                      },
                      {
                        type => 'text',
                        content => 'PROFILER_instance_index '
                      },
                      {
                        type => 'linebreak'
                      },
                      {
                        type => 'text',
                        content => ' Индекс локального профилировщика.'
                      }
                    ]
                  }
                ]
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'PROFILER_begin_time',
                type => 'PROFILER_timestruct'
              },
              {
                declaration_name => 'PROFILER_end_time',
                type => 'PROFILER_timestruct'
              },
              {
                declaration_name => 'PROFILER_instance_index',
                type => 'int32_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'PROFILER_refresh_times_called',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Обновить общее число вызовов данного профилировщика.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Общее число вызовов профилировщика даёт понять, сколько раз управление достигло секции, которую профилирует данный профилировщик. '
                },
                params => [
                  {
                    parameters => [
                      {
                        name => 'int32_t'
                      }
                    ],
                    doc => [
                      {
                        type => 'text',
                        content => 'PROFILER_instance_index '
                      },
                      {
                        type => 'linebreak'
                      },
                      {
                        type => 'text',
                        content => ' Индекс локального профилировщика.'
                      }
                    ]
                  }
                ]
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'PROFILER_instance_index',
                type => 'int32_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'PROFILER_get_free_instance_index',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Определяет индекс следующего свободного профилировщика.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Когда профилировщик начинает свою работу впервые, система присваивает ему некоторый индекс, посредством которого с профилировщиком в дальнейшем выполняются все остальные манипуляции. '
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'int32_t индекс следующего свободного профилировщика'
                    }
                  ]
                }
              ]
            },
            type => 'int32_t',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'PROFILER_instance_init',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Инициализирует экземпляр профилировщика.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Когда профилировщик начинает свою работу впервые, система профилировки запоминает его положение в исходном коде. '
                },
                params => [
                  {
                    parameters => [
                      {
                        name => 'const'
                      }
                    ],
                    doc => [
                      {
                        type => 'text',
                        content => 'char *file '
                      },
                      {
                        type => 'linebreak'
                      },
                      {
                        type => 'text',
                        content => ' Название файла, в котором работает профилировщик. '
                      }
                    ]
                  },
                  {
                    parameters => [
                      {
                        name => 'const'
                      }
                    ],
                    doc => [
                      {
                        type => 'parbreak'
                      },
                      {
                        type => 'text',
                        content => 'char *function '
                      },
                      {
                        type => 'linebreak'
                      },
                      {
                        type => 'text',
                        content => ' Название функции, в которой работает профилировщик. '
                      }
                    ]
                  },
                  {
                    parameters => [
                      {
                        name => 'const'
                      }
                    ],
                    doc => [
                      {
                        type => 'parbreak'
                      },
                      {
                        type => 'text',
                        content => 'int32_t line '
                      },
                      {
                        type => 'linebreak'
                      },
                      {
                        type => 'text',
                        content => ' Номер строки, в которой начинается выполнение профилировщика. Профилировщик измеряет время выполнения сегмента кода от этой строки до вызова PROFILIER_local_stop() '
                      }
                    ]
                  },
                  {
                    parameters => [
                      {
                        name => 'const'
                      }
                    ],
                    doc => [
                      {
                        type => 'parbreak'
                      },
                      {
                        type => 'text',
                        content => 'int32_t PROFILER_instance_index '
                      },
                      {
                        type => 'linebreak'
                      },
                      {
                        type => 'text',
                        content => ' Индекс инициализируемого профилировщика.'
                      }
                    ]
                  }
                ]
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'file',
                type => 'const char *'
              },
              {
                declaration_name => 'function',
                type => 'const char *'
              },
              {
                declaration_name => 'line',
                type => 'const int32_t'
              },
              {
                declaration_name => 'PROFILER_instance_index',
                type => 'const int32_t'
              }
            ]
          },
          {
            kind => 'function',
            name => 'PROFILER_instance_is_not_initialized',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Сообщает инициализирован ли профилировщик или нет.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Возвращает 0, если профилировщик ещё не инициализирован (работает впервые). Возвращает значение отличное от 0, если профилировщик уже не нуждается в инициализации (работает не в первые). '
                },
                params => [
                  {
                    parameters => [
                      {
                        name => 'int32_t'
                      }
                    ],
                    doc => [
                      {
                        type => 'text',
                        content => 'PROFILER_instance_index '
                      },
                      {
                        type => 'linebreak'
                      },
                      {
                        type => 'text',
                        content => ' Индекс профилировщика. '
                      }
                    ]
                  }
                ],
                {
                  return => [
                  ]
                }
              ]
            },
            type => 'uint8_t',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'PROFILER_instance_index',
                type => 'int32_t'
              }
            ]
          }
        ]
      },
      variables => {
        members => [
          {
            kind => 'variable',
            name => 'PROFILER_instance_last_index',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Индекс последнего инициализированного профилировщика.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Инициализирован значением PROFILER_INSTANCE_NOT_INITIALIZED, поскольку в начальный момент ни один профилировщик ещё не инициализирован.'
                }
              ]
            },
            type => 'int32_t'
          },
          {
            kind => 'variable',
            name => 'PROFILER_files_names',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const char *'
          },
          {
            kind => 'variable',
            name => 'PROFILER_procedures_names',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'const char *'
          },
          {
            kind => 'variable',
            name => 'PROFILER_lines_numbers',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint32_t'
          },
          {
            kind => 'variable',
            name => 'PROFILER_times_called',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint32_t'
          },
          {
            kind => 'variable',
            name => 'PROFILER_total_times',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'PROFILER_timestruct'
          },
          {
            kind => 'variable',
            name => 'PROFILER_end_time',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'static PROFILER_timestruct'
          },
          {
            kind => 'variable',
            name => 'PROFILER_instance_index',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'static PROFILER_timestruct int32_t'
          },
          {
            kind => 'variable',
            name => 'function',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'static const char *'
          },
          {
            kind => 'variable',
            name => 'line',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'static const char const int32_t'
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'text',
            content => 'Файл '
          },
          {
            type => 'url',
            link => '_p_r_o_f_i_l_i_n_g__tools_8h',
            content => 'PROFILING_tools.h'
          },
          {
            type => 'text',
            content => ' является частью библиотеки EmbedPROFILER - библиотеки профилировщика времени вызовов. Профилировщик времени вызовов - средство анализа исходного кода программ, представляющее программистам и инженерам анализировать время, затраченное на выполнение того или иного участка кода в процентном соотношении (относительно общего времени работы профилировщика).'
          }
        ]
      },
      detailed => {
        doc => [
          {
            author => [
              {
                type => 'text',
                content => 'Sergeev Ruslan. OOO SPUTNIX, MIPT High-Precision Attitude Control Systems Laboratory '
              }
            ]
          },
          {
            version => [
              {
                type => 'text',
                content => 'V1.0.0 '
              }
            ]
          },
          {
            date => [
              {
                type => 'text',
                content => '23-January-2016 '
              }
            ]
          },
          {
            attention => [
              {
                type => 'text',
                content => 'THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME. AS A RESULT, OOO SPUTNIX, MIPT High-Precision Attitude Control Systems Laboratory SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.'
              }
            ]
          },
          {
            type => 'style',
            style => 'center',
            enable => 'yes'
          },
          {
            type => 'symbol',
            symbol => 'copyright'
          },
          {
            type => 'text',
            content => ' COPYRIGHT 2016 RUSLAN SERGEEV'
          },
          {
            type => 'style',
            style => 'center',
            enable => 'no'
          }
        ]
      }
    }
  ],
  groups => [
    {
      name => 'Портируемая_секция',
      title => 'Портируемая_секция',
      files => [
      ],
      classes => [
      ],
      namespaces => [
      ],
      pages => [
      ],
      groups => [
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'PROFILER_TOTAL_PROFILERS',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Максимальное число работающих профилировщиков времени вызова.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Это число определяет размеры массивов для хранения указателей на названия функций, имена файлов, номера строк и число вызовов.'
                }
              ]
            },
            initializer => '1024'
          },
          {
            kind => 'define',
            name => 'PROFILER_global_stop',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Окончание работы глобального профилировщика.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Запоминается время окончания работы системы профилирования. Которое используется в дальнейшем для расчёта времени работы системы профилирования.Добавлено в портируемый раздел, поскольку завершение работы профилировщика может быть платформо-зависимой.'
                }
              ]
            },
            parameters => [
            ],
            initializer => 'PROFILER_local_stop()'
          }
        ]
      },
      typedefs => {
        members => [
          {
            kind => 'typedef',
            name => 'PROFILER_timestruct',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Тип переменной для хранения измерений времени.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Для оптимальной работы не рекомендуется хранение времени в целочисленных типах.'
                }
              ]
            },
            type => 'struct timespec'
          }
        ]
      },
      functions => {
        members => [
          {
            kind => 'function',
            name => 'PROFILER_log',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Вывести отчёт о работе профилировщика.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Сообщает затраченное на работу каждого профилировщика время, имена файлов, номера строк, названия функций где был создан данный профилировщик. Также сообщает число вызовов данного профилировщика.'
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'PROFILER_get_current_time',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Получить текущее время в системе.'
                }
              ]
            },
            detailed => {
              doc => [
                params => [
                  {
                    parameters => [
                      {
                        name => 'PROFILER_timestruct'
                      }
                    ],
                    doc => [
                      {
                        type => 'text',
                        content => '*PROFILER_timestruct_instance '
                      },
                      {
                        type => 'linebreak'
                      },
                      {
                        type => 'text',
                        content => ' Указатель на структуру, в которой будет сохранено системное время.'
                      }
                    ]
                  }
                ]
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'PROFILER_timestruct_instance',
                type => 'PROFILER_timestruct *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'PROFILER_refresh_time_consumed',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'text',
                  content => 'Обновить общее время затраченное на работу указанного профилировщика за все его вызовы.'
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'text',
                  content => 'Добавляет время потраченное указанным профилировщиком за последний вызов к общему времени за все вызовы, затраченному указанным профилировщиком. '
                },
                params => [
                  {
                    parameters => [
                      {
                        name => 'PROFILER_timestruct'
                      }
                    ],
                    doc => [
                      {
                        type => 'text',
                        content => 'PROFILER_begin_time '
                      },
                      {
                        type => 'linebreak'
                      },
                      {
                        type => 'text',
                        content => ' Время начала работы (очередного вызова) локального профилировщика. '
                      }
                    ]
                  },
                  {
                    parameters => [
                      {
                        name => 'PROFILER_timestruct'
                      }
                    ],
                    doc => [
                      {
                        type => 'parbreak'
                      },
                      {
                        type => 'text',
                        content => 'PROFILER_end_time '
                      },
                      {
                        type => 'linebreak'
                      },
                      {
                        type => 'text',
                        content => ' Время окончания работы (очередного завершения) локального профилировщика. '
                      }
                    ]
                  },
                  {
                    parameters => [
                      {
                        name => 'int32_t'
                      }
                    ],
                    doc => [
                      {
                        type => 'parbreak'
                      },
                      {
                        type => 'text',
                        content => 'PROFILER_instance_index '
                      },
                      {
                        type => 'linebreak'
                      },
                      {
                        type => 'text',
                        content => ' Индекс локального профилировщика.'
                      }
                    ]
                  }
                ]
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'PROFILER_begin_time',
                type => 'PROFILER_timestruct'
              },
              {
                declaration_name => 'PROFILER_end_time',
                type => 'PROFILER_timestruct'
              },
              {
                declaration_name => 'PROFILER_instance_index',
                type => 'int32_t'
              }
            ]
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'text',
            content => 'Эти функции необходимо определить для вашей платформы. Остальная часть кода профилировщика является платформо-независимой.'
          }
        ]
      },
      detailed => {
        doc => [
          {
            type => 'text',
            content => 'EmbedPROFILER проектировался для исполнения во встраиваемых системах независимо от аппаратной платформы. Для того, чтобы EmbedPROFILER можно было перенести на интересующую вас платформу, необходимо реализовать на данной платформе определённые в этой секции процедуры и макросы.'
          }
        ]
      }
    }
  ],
  pages => [
  ]
};
1;
