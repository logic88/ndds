# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef RTIBOOST_PREPROCESSOR_SEQ_DETAIL_SPLIT_HPP
# define RTIBOOST_PREPROCESSOR_SEQ_DETAIL_SPLIT_HPP
#
# include <rtiboost/preprocessor/config/config.hpp>
#
# /* RTIBOOST_PP_SEQ_SPLIT */
#
# define RTIBOOST_PP_SEQ_SPLIT(n, seq) RTIBOOST_PP_SEQ_SPLIT_D(n, seq)
#
# if ~RTIBOOST_PP_CONFIG_FLAGS() & RTIBOOST_PP_CONFIG_MWCC()
#    define RTIBOOST_PP_SEQ_SPLIT_D(n, seq) (RTIBOOST_PP_SEQ_SPLIT_ ## n seq)
# else
#    define RTIBOOST_PP_SEQ_SPLIT_D(n, seq) (RTIBOOST_PP_SEQ_SPLIT_ ## n ## seq)
# endif
#
# define RTIBOOST_PP_SEQ_SPLIT_1(x) (x),
# define RTIBOOST_PP_SEQ_SPLIT_2(x) (x) RTIBOOST_PP_SEQ_SPLIT_1
# define RTIBOOST_PP_SEQ_SPLIT_3(x) (x) RTIBOOST_PP_SEQ_SPLIT_2
# define RTIBOOST_PP_SEQ_SPLIT_4(x) (x) RTIBOOST_PP_SEQ_SPLIT_3
# define RTIBOOST_PP_SEQ_SPLIT_5(x) (x) RTIBOOST_PP_SEQ_SPLIT_4
# define RTIBOOST_PP_SEQ_SPLIT_6(x) (x) RTIBOOST_PP_SEQ_SPLIT_5
# define RTIBOOST_PP_SEQ_SPLIT_7(x) (x) RTIBOOST_PP_SEQ_SPLIT_6
# define RTIBOOST_PP_SEQ_SPLIT_8(x) (x) RTIBOOST_PP_SEQ_SPLIT_7
# define RTIBOOST_PP_SEQ_SPLIT_9(x) (x) RTIBOOST_PP_SEQ_SPLIT_8
# define RTIBOOST_PP_SEQ_SPLIT_10(x) (x) RTIBOOST_PP_SEQ_SPLIT_9
# define RTIBOOST_PP_SEQ_SPLIT_11(x) (x) RTIBOOST_PP_SEQ_SPLIT_10
# define RTIBOOST_PP_SEQ_SPLIT_12(x) (x) RTIBOOST_PP_SEQ_SPLIT_11
# define RTIBOOST_PP_SEQ_SPLIT_13(x) (x) RTIBOOST_PP_SEQ_SPLIT_12
# define RTIBOOST_PP_SEQ_SPLIT_14(x) (x) RTIBOOST_PP_SEQ_SPLIT_13
# define RTIBOOST_PP_SEQ_SPLIT_15(x) (x) RTIBOOST_PP_SEQ_SPLIT_14
# define RTIBOOST_PP_SEQ_SPLIT_16(x) (x) RTIBOOST_PP_SEQ_SPLIT_15
# define RTIBOOST_PP_SEQ_SPLIT_17(x) (x) RTIBOOST_PP_SEQ_SPLIT_16
# define RTIBOOST_PP_SEQ_SPLIT_18(x) (x) RTIBOOST_PP_SEQ_SPLIT_17
# define RTIBOOST_PP_SEQ_SPLIT_19(x) (x) RTIBOOST_PP_SEQ_SPLIT_18
# define RTIBOOST_PP_SEQ_SPLIT_20(x) (x) RTIBOOST_PP_SEQ_SPLIT_19
# define RTIBOOST_PP_SEQ_SPLIT_21(x) (x) RTIBOOST_PP_SEQ_SPLIT_20
# define RTIBOOST_PP_SEQ_SPLIT_22(x) (x) RTIBOOST_PP_SEQ_SPLIT_21
# define RTIBOOST_PP_SEQ_SPLIT_23(x) (x) RTIBOOST_PP_SEQ_SPLIT_22
# define RTIBOOST_PP_SEQ_SPLIT_24(x) (x) RTIBOOST_PP_SEQ_SPLIT_23
# define RTIBOOST_PP_SEQ_SPLIT_25(x) (x) RTIBOOST_PP_SEQ_SPLIT_24
# define RTIBOOST_PP_SEQ_SPLIT_26(x) (x) RTIBOOST_PP_SEQ_SPLIT_25
# define RTIBOOST_PP_SEQ_SPLIT_27(x) (x) RTIBOOST_PP_SEQ_SPLIT_26
# define RTIBOOST_PP_SEQ_SPLIT_28(x) (x) RTIBOOST_PP_SEQ_SPLIT_27
# define RTIBOOST_PP_SEQ_SPLIT_29(x) (x) RTIBOOST_PP_SEQ_SPLIT_28
# define RTIBOOST_PP_SEQ_SPLIT_30(x) (x) RTIBOOST_PP_SEQ_SPLIT_29
# define RTIBOOST_PP_SEQ_SPLIT_31(x) (x) RTIBOOST_PP_SEQ_SPLIT_30
# define RTIBOOST_PP_SEQ_SPLIT_32(x) (x) RTIBOOST_PP_SEQ_SPLIT_31
# define RTIBOOST_PP_SEQ_SPLIT_33(x) (x) RTIBOOST_PP_SEQ_SPLIT_32
# define RTIBOOST_PP_SEQ_SPLIT_34(x) (x) RTIBOOST_PP_SEQ_SPLIT_33
# define RTIBOOST_PP_SEQ_SPLIT_35(x) (x) RTIBOOST_PP_SEQ_SPLIT_34
# define RTIBOOST_PP_SEQ_SPLIT_36(x) (x) RTIBOOST_PP_SEQ_SPLIT_35
# define RTIBOOST_PP_SEQ_SPLIT_37(x) (x) RTIBOOST_PP_SEQ_SPLIT_36
# define RTIBOOST_PP_SEQ_SPLIT_38(x) (x) RTIBOOST_PP_SEQ_SPLIT_37
# define RTIBOOST_PP_SEQ_SPLIT_39(x) (x) RTIBOOST_PP_SEQ_SPLIT_38
# define RTIBOOST_PP_SEQ_SPLIT_40(x) (x) RTIBOOST_PP_SEQ_SPLIT_39
# define RTIBOOST_PP_SEQ_SPLIT_41(x) (x) RTIBOOST_PP_SEQ_SPLIT_40
# define RTIBOOST_PP_SEQ_SPLIT_42(x) (x) RTIBOOST_PP_SEQ_SPLIT_41
# define RTIBOOST_PP_SEQ_SPLIT_43(x) (x) RTIBOOST_PP_SEQ_SPLIT_42
# define RTIBOOST_PP_SEQ_SPLIT_44(x) (x) RTIBOOST_PP_SEQ_SPLIT_43
# define RTIBOOST_PP_SEQ_SPLIT_45(x) (x) RTIBOOST_PP_SEQ_SPLIT_44
# define RTIBOOST_PP_SEQ_SPLIT_46(x) (x) RTIBOOST_PP_SEQ_SPLIT_45
# define RTIBOOST_PP_SEQ_SPLIT_47(x) (x) RTIBOOST_PP_SEQ_SPLIT_46
# define RTIBOOST_PP_SEQ_SPLIT_48(x) (x) RTIBOOST_PP_SEQ_SPLIT_47
# define RTIBOOST_PP_SEQ_SPLIT_49(x) (x) RTIBOOST_PP_SEQ_SPLIT_48
# define RTIBOOST_PP_SEQ_SPLIT_50(x) (x) RTIBOOST_PP_SEQ_SPLIT_49
# define RTIBOOST_PP_SEQ_SPLIT_51(x) (x) RTIBOOST_PP_SEQ_SPLIT_50
# define RTIBOOST_PP_SEQ_SPLIT_52(x) (x) RTIBOOST_PP_SEQ_SPLIT_51
# define RTIBOOST_PP_SEQ_SPLIT_53(x) (x) RTIBOOST_PP_SEQ_SPLIT_52
# define RTIBOOST_PP_SEQ_SPLIT_54(x) (x) RTIBOOST_PP_SEQ_SPLIT_53
# define RTIBOOST_PP_SEQ_SPLIT_55(x) (x) RTIBOOST_PP_SEQ_SPLIT_54
# define RTIBOOST_PP_SEQ_SPLIT_56(x) (x) RTIBOOST_PP_SEQ_SPLIT_55
# define RTIBOOST_PP_SEQ_SPLIT_57(x) (x) RTIBOOST_PP_SEQ_SPLIT_56
# define RTIBOOST_PP_SEQ_SPLIT_58(x) (x) RTIBOOST_PP_SEQ_SPLIT_57
# define RTIBOOST_PP_SEQ_SPLIT_59(x) (x) RTIBOOST_PP_SEQ_SPLIT_58
# define RTIBOOST_PP_SEQ_SPLIT_60(x) (x) RTIBOOST_PP_SEQ_SPLIT_59
# define RTIBOOST_PP_SEQ_SPLIT_61(x) (x) RTIBOOST_PP_SEQ_SPLIT_60
# define RTIBOOST_PP_SEQ_SPLIT_62(x) (x) RTIBOOST_PP_SEQ_SPLIT_61
# define RTIBOOST_PP_SEQ_SPLIT_63(x) (x) RTIBOOST_PP_SEQ_SPLIT_62
# define RTIBOOST_PP_SEQ_SPLIT_64(x) (x) RTIBOOST_PP_SEQ_SPLIT_63
# define RTIBOOST_PP_SEQ_SPLIT_65(x) (x) RTIBOOST_PP_SEQ_SPLIT_64
# define RTIBOOST_PP_SEQ_SPLIT_66(x) (x) RTIBOOST_PP_SEQ_SPLIT_65
# define RTIBOOST_PP_SEQ_SPLIT_67(x) (x) RTIBOOST_PP_SEQ_SPLIT_66
# define RTIBOOST_PP_SEQ_SPLIT_68(x) (x) RTIBOOST_PP_SEQ_SPLIT_67
# define RTIBOOST_PP_SEQ_SPLIT_69(x) (x) RTIBOOST_PP_SEQ_SPLIT_68
# define RTIBOOST_PP_SEQ_SPLIT_70(x) (x) RTIBOOST_PP_SEQ_SPLIT_69
# define RTIBOOST_PP_SEQ_SPLIT_71(x) (x) RTIBOOST_PP_SEQ_SPLIT_70
# define RTIBOOST_PP_SEQ_SPLIT_72(x) (x) RTIBOOST_PP_SEQ_SPLIT_71
# define RTIBOOST_PP_SEQ_SPLIT_73(x) (x) RTIBOOST_PP_SEQ_SPLIT_72
# define RTIBOOST_PP_SEQ_SPLIT_74(x) (x) RTIBOOST_PP_SEQ_SPLIT_73
# define RTIBOOST_PP_SEQ_SPLIT_75(x) (x) RTIBOOST_PP_SEQ_SPLIT_74
# define RTIBOOST_PP_SEQ_SPLIT_76(x) (x) RTIBOOST_PP_SEQ_SPLIT_75
# define RTIBOOST_PP_SEQ_SPLIT_77(x) (x) RTIBOOST_PP_SEQ_SPLIT_76
# define RTIBOOST_PP_SEQ_SPLIT_78(x) (x) RTIBOOST_PP_SEQ_SPLIT_77
# define RTIBOOST_PP_SEQ_SPLIT_79(x) (x) RTIBOOST_PP_SEQ_SPLIT_78
# define RTIBOOST_PP_SEQ_SPLIT_80(x) (x) RTIBOOST_PP_SEQ_SPLIT_79
# define RTIBOOST_PP_SEQ_SPLIT_81(x) (x) RTIBOOST_PP_SEQ_SPLIT_80
# define RTIBOOST_PP_SEQ_SPLIT_82(x) (x) RTIBOOST_PP_SEQ_SPLIT_81
# define RTIBOOST_PP_SEQ_SPLIT_83(x) (x) RTIBOOST_PP_SEQ_SPLIT_82
# define RTIBOOST_PP_SEQ_SPLIT_84(x) (x) RTIBOOST_PP_SEQ_SPLIT_83
# define RTIBOOST_PP_SEQ_SPLIT_85(x) (x) RTIBOOST_PP_SEQ_SPLIT_84
# define RTIBOOST_PP_SEQ_SPLIT_86(x) (x) RTIBOOST_PP_SEQ_SPLIT_85
# define RTIBOOST_PP_SEQ_SPLIT_87(x) (x) RTIBOOST_PP_SEQ_SPLIT_86
# define RTIBOOST_PP_SEQ_SPLIT_88(x) (x) RTIBOOST_PP_SEQ_SPLIT_87
# define RTIBOOST_PP_SEQ_SPLIT_89(x) (x) RTIBOOST_PP_SEQ_SPLIT_88
# define RTIBOOST_PP_SEQ_SPLIT_90(x) (x) RTIBOOST_PP_SEQ_SPLIT_89
# define RTIBOOST_PP_SEQ_SPLIT_91(x) (x) RTIBOOST_PP_SEQ_SPLIT_90
# define RTIBOOST_PP_SEQ_SPLIT_92(x) (x) RTIBOOST_PP_SEQ_SPLIT_91
# define RTIBOOST_PP_SEQ_SPLIT_93(x) (x) RTIBOOST_PP_SEQ_SPLIT_92
# define RTIBOOST_PP_SEQ_SPLIT_94(x) (x) RTIBOOST_PP_SEQ_SPLIT_93
# define RTIBOOST_PP_SEQ_SPLIT_95(x) (x) RTIBOOST_PP_SEQ_SPLIT_94
# define RTIBOOST_PP_SEQ_SPLIT_96(x) (x) RTIBOOST_PP_SEQ_SPLIT_95
# define RTIBOOST_PP_SEQ_SPLIT_97(x) (x) RTIBOOST_PP_SEQ_SPLIT_96
# define RTIBOOST_PP_SEQ_SPLIT_98(x) (x) RTIBOOST_PP_SEQ_SPLIT_97
# define RTIBOOST_PP_SEQ_SPLIT_99(x) (x) RTIBOOST_PP_SEQ_SPLIT_98
# define RTIBOOST_PP_SEQ_SPLIT_100(x) (x) RTIBOOST_PP_SEQ_SPLIT_99
# define RTIBOOST_PP_SEQ_SPLIT_101(x) (x) RTIBOOST_PP_SEQ_SPLIT_100
# define RTIBOOST_PP_SEQ_SPLIT_102(x) (x) RTIBOOST_PP_SEQ_SPLIT_101
# define RTIBOOST_PP_SEQ_SPLIT_103(x) (x) RTIBOOST_PP_SEQ_SPLIT_102
# define RTIBOOST_PP_SEQ_SPLIT_104(x) (x) RTIBOOST_PP_SEQ_SPLIT_103
# define RTIBOOST_PP_SEQ_SPLIT_105(x) (x) RTIBOOST_PP_SEQ_SPLIT_104
# define RTIBOOST_PP_SEQ_SPLIT_106(x) (x) RTIBOOST_PP_SEQ_SPLIT_105
# define RTIBOOST_PP_SEQ_SPLIT_107(x) (x) RTIBOOST_PP_SEQ_SPLIT_106
# define RTIBOOST_PP_SEQ_SPLIT_108(x) (x) RTIBOOST_PP_SEQ_SPLIT_107
# define RTIBOOST_PP_SEQ_SPLIT_109(x) (x) RTIBOOST_PP_SEQ_SPLIT_108
# define RTIBOOST_PP_SEQ_SPLIT_110(x) (x) RTIBOOST_PP_SEQ_SPLIT_109
# define RTIBOOST_PP_SEQ_SPLIT_111(x) (x) RTIBOOST_PP_SEQ_SPLIT_110
# define RTIBOOST_PP_SEQ_SPLIT_112(x) (x) RTIBOOST_PP_SEQ_SPLIT_111
# define RTIBOOST_PP_SEQ_SPLIT_113(x) (x) RTIBOOST_PP_SEQ_SPLIT_112
# define RTIBOOST_PP_SEQ_SPLIT_114(x) (x) RTIBOOST_PP_SEQ_SPLIT_113
# define RTIBOOST_PP_SEQ_SPLIT_115(x) (x) RTIBOOST_PP_SEQ_SPLIT_114
# define RTIBOOST_PP_SEQ_SPLIT_116(x) (x) RTIBOOST_PP_SEQ_SPLIT_115
# define RTIBOOST_PP_SEQ_SPLIT_117(x) (x) RTIBOOST_PP_SEQ_SPLIT_116
# define RTIBOOST_PP_SEQ_SPLIT_118(x) (x) RTIBOOST_PP_SEQ_SPLIT_117
# define RTIBOOST_PP_SEQ_SPLIT_119(x) (x) RTIBOOST_PP_SEQ_SPLIT_118
# define RTIBOOST_PP_SEQ_SPLIT_120(x) (x) RTIBOOST_PP_SEQ_SPLIT_119
# define RTIBOOST_PP_SEQ_SPLIT_121(x) (x) RTIBOOST_PP_SEQ_SPLIT_120
# define RTIBOOST_PP_SEQ_SPLIT_122(x) (x) RTIBOOST_PP_SEQ_SPLIT_121
# define RTIBOOST_PP_SEQ_SPLIT_123(x) (x) RTIBOOST_PP_SEQ_SPLIT_122
# define RTIBOOST_PP_SEQ_SPLIT_124(x) (x) RTIBOOST_PP_SEQ_SPLIT_123
# define RTIBOOST_PP_SEQ_SPLIT_125(x) (x) RTIBOOST_PP_SEQ_SPLIT_124
# define RTIBOOST_PP_SEQ_SPLIT_126(x) (x) RTIBOOST_PP_SEQ_SPLIT_125
# define RTIBOOST_PP_SEQ_SPLIT_127(x) (x) RTIBOOST_PP_SEQ_SPLIT_126
# define RTIBOOST_PP_SEQ_SPLIT_128(x) (x) RTIBOOST_PP_SEQ_SPLIT_127
# define RTIBOOST_PP_SEQ_SPLIT_129(x) (x) RTIBOOST_PP_SEQ_SPLIT_128
# define RTIBOOST_PP_SEQ_SPLIT_130(x) (x) RTIBOOST_PP_SEQ_SPLIT_129
# define RTIBOOST_PP_SEQ_SPLIT_131(x) (x) RTIBOOST_PP_SEQ_SPLIT_130
# define RTIBOOST_PP_SEQ_SPLIT_132(x) (x) RTIBOOST_PP_SEQ_SPLIT_131
# define RTIBOOST_PP_SEQ_SPLIT_133(x) (x) RTIBOOST_PP_SEQ_SPLIT_132
# define RTIBOOST_PP_SEQ_SPLIT_134(x) (x) RTIBOOST_PP_SEQ_SPLIT_133
# define RTIBOOST_PP_SEQ_SPLIT_135(x) (x) RTIBOOST_PP_SEQ_SPLIT_134
# define RTIBOOST_PP_SEQ_SPLIT_136(x) (x) RTIBOOST_PP_SEQ_SPLIT_135
# define RTIBOOST_PP_SEQ_SPLIT_137(x) (x) RTIBOOST_PP_SEQ_SPLIT_136
# define RTIBOOST_PP_SEQ_SPLIT_138(x) (x) RTIBOOST_PP_SEQ_SPLIT_137
# define RTIBOOST_PP_SEQ_SPLIT_139(x) (x) RTIBOOST_PP_SEQ_SPLIT_138
# define RTIBOOST_PP_SEQ_SPLIT_140(x) (x) RTIBOOST_PP_SEQ_SPLIT_139
# define RTIBOOST_PP_SEQ_SPLIT_141(x) (x) RTIBOOST_PP_SEQ_SPLIT_140
# define RTIBOOST_PP_SEQ_SPLIT_142(x) (x) RTIBOOST_PP_SEQ_SPLIT_141
# define RTIBOOST_PP_SEQ_SPLIT_143(x) (x) RTIBOOST_PP_SEQ_SPLIT_142
# define RTIBOOST_PP_SEQ_SPLIT_144(x) (x) RTIBOOST_PP_SEQ_SPLIT_143
# define RTIBOOST_PP_SEQ_SPLIT_145(x) (x) RTIBOOST_PP_SEQ_SPLIT_144
# define RTIBOOST_PP_SEQ_SPLIT_146(x) (x) RTIBOOST_PP_SEQ_SPLIT_145
# define RTIBOOST_PP_SEQ_SPLIT_147(x) (x) RTIBOOST_PP_SEQ_SPLIT_146
# define RTIBOOST_PP_SEQ_SPLIT_148(x) (x) RTIBOOST_PP_SEQ_SPLIT_147
# define RTIBOOST_PP_SEQ_SPLIT_149(x) (x) RTIBOOST_PP_SEQ_SPLIT_148
# define RTIBOOST_PP_SEQ_SPLIT_150(x) (x) RTIBOOST_PP_SEQ_SPLIT_149
# define RTIBOOST_PP_SEQ_SPLIT_151(x) (x) RTIBOOST_PP_SEQ_SPLIT_150
# define RTIBOOST_PP_SEQ_SPLIT_152(x) (x) RTIBOOST_PP_SEQ_SPLIT_151
# define RTIBOOST_PP_SEQ_SPLIT_153(x) (x) RTIBOOST_PP_SEQ_SPLIT_152
# define RTIBOOST_PP_SEQ_SPLIT_154(x) (x) RTIBOOST_PP_SEQ_SPLIT_153
# define RTIBOOST_PP_SEQ_SPLIT_155(x) (x) RTIBOOST_PP_SEQ_SPLIT_154
# define RTIBOOST_PP_SEQ_SPLIT_156(x) (x) RTIBOOST_PP_SEQ_SPLIT_155
# define RTIBOOST_PP_SEQ_SPLIT_157(x) (x) RTIBOOST_PP_SEQ_SPLIT_156
# define RTIBOOST_PP_SEQ_SPLIT_158(x) (x) RTIBOOST_PP_SEQ_SPLIT_157
# define RTIBOOST_PP_SEQ_SPLIT_159(x) (x) RTIBOOST_PP_SEQ_SPLIT_158
# define RTIBOOST_PP_SEQ_SPLIT_160(x) (x) RTIBOOST_PP_SEQ_SPLIT_159
# define RTIBOOST_PP_SEQ_SPLIT_161(x) (x) RTIBOOST_PP_SEQ_SPLIT_160
# define RTIBOOST_PP_SEQ_SPLIT_162(x) (x) RTIBOOST_PP_SEQ_SPLIT_161
# define RTIBOOST_PP_SEQ_SPLIT_163(x) (x) RTIBOOST_PP_SEQ_SPLIT_162
# define RTIBOOST_PP_SEQ_SPLIT_164(x) (x) RTIBOOST_PP_SEQ_SPLIT_163
# define RTIBOOST_PP_SEQ_SPLIT_165(x) (x) RTIBOOST_PP_SEQ_SPLIT_164
# define RTIBOOST_PP_SEQ_SPLIT_166(x) (x) RTIBOOST_PP_SEQ_SPLIT_165
# define RTIBOOST_PP_SEQ_SPLIT_167(x) (x) RTIBOOST_PP_SEQ_SPLIT_166
# define RTIBOOST_PP_SEQ_SPLIT_168(x) (x) RTIBOOST_PP_SEQ_SPLIT_167
# define RTIBOOST_PP_SEQ_SPLIT_169(x) (x) RTIBOOST_PP_SEQ_SPLIT_168
# define RTIBOOST_PP_SEQ_SPLIT_170(x) (x) RTIBOOST_PP_SEQ_SPLIT_169
# define RTIBOOST_PP_SEQ_SPLIT_171(x) (x) RTIBOOST_PP_SEQ_SPLIT_170
# define RTIBOOST_PP_SEQ_SPLIT_172(x) (x) RTIBOOST_PP_SEQ_SPLIT_171
# define RTIBOOST_PP_SEQ_SPLIT_173(x) (x) RTIBOOST_PP_SEQ_SPLIT_172
# define RTIBOOST_PP_SEQ_SPLIT_174(x) (x) RTIBOOST_PP_SEQ_SPLIT_173
# define RTIBOOST_PP_SEQ_SPLIT_175(x) (x) RTIBOOST_PP_SEQ_SPLIT_174
# define RTIBOOST_PP_SEQ_SPLIT_176(x) (x) RTIBOOST_PP_SEQ_SPLIT_175
# define RTIBOOST_PP_SEQ_SPLIT_177(x) (x) RTIBOOST_PP_SEQ_SPLIT_176
# define RTIBOOST_PP_SEQ_SPLIT_178(x) (x) RTIBOOST_PP_SEQ_SPLIT_177
# define RTIBOOST_PP_SEQ_SPLIT_179(x) (x) RTIBOOST_PP_SEQ_SPLIT_178
# define RTIBOOST_PP_SEQ_SPLIT_180(x) (x) RTIBOOST_PP_SEQ_SPLIT_179
# define RTIBOOST_PP_SEQ_SPLIT_181(x) (x) RTIBOOST_PP_SEQ_SPLIT_180
# define RTIBOOST_PP_SEQ_SPLIT_182(x) (x) RTIBOOST_PP_SEQ_SPLIT_181
# define RTIBOOST_PP_SEQ_SPLIT_183(x) (x) RTIBOOST_PP_SEQ_SPLIT_182
# define RTIBOOST_PP_SEQ_SPLIT_184(x) (x) RTIBOOST_PP_SEQ_SPLIT_183
# define RTIBOOST_PP_SEQ_SPLIT_185(x) (x) RTIBOOST_PP_SEQ_SPLIT_184
# define RTIBOOST_PP_SEQ_SPLIT_186(x) (x) RTIBOOST_PP_SEQ_SPLIT_185
# define RTIBOOST_PP_SEQ_SPLIT_187(x) (x) RTIBOOST_PP_SEQ_SPLIT_186
# define RTIBOOST_PP_SEQ_SPLIT_188(x) (x) RTIBOOST_PP_SEQ_SPLIT_187
# define RTIBOOST_PP_SEQ_SPLIT_189(x) (x) RTIBOOST_PP_SEQ_SPLIT_188
# define RTIBOOST_PP_SEQ_SPLIT_190(x) (x) RTIBOOST_PP_SEQ_SPLIT_189
# define RTIBOOST_PP_SEQ_SPLIT_191(x) (x) RTIBOOST_PP_SEQ_SPLIT_190
# define RTIBOOST_PP_SEQ_SPLIT_192(x) (x) RTIBOOST_PP_SEQ_SPLIT_191
# define RTIBOOST_PP_SEQ_SPLIT_193(x) (x) RTIBOOST_PP_SEQ_SPLIT_192
# define RTIBOOST_PP_SEQ_SPLIT_194(x) (x) RTIBOOST_PP_SEQ_SPLIT_193
# define RTIBOOST_PP_SEQ_SPLIT_195(x) (x) RTIBOOST_PP_SEQ_SPLIT_194
# define RTIBOOST_PP_SEQ_SPLIT_196(x) (x) RTIBOOST_PP_SEQ_SPLIT_195
# define RTIBOOST_PP_SEQ_SPLIT_197(x) (x) RTIBOOST_PP_SEQ_SPLIT_196
# define RTIBOOST_PP_SEQ_SPLIT_198(x) (x) RTIBOOST_PP_SEQ_SPLIT_197
# define RTIBOOST_PP_SEQ_SPLIT_199(x) (x) RTIBOOST_PP_SEQ_SPLIT_198
# define RTIBOOST_PP_SEQ_SPLIT_200(x) (x) RTIBOOST_PP_SEQ_SPLIT_199
# define RTIBOOST_PP_SEQ_SPLIT_201(x) (x) RTIBOOST_PP_SEQ_SPLIT_200
# define RTIBOOST_PP_SEQ_SPLIT_202(x) (x) RTIBOOST_PP_SEQ_SPLIT_201
# define RTIBOOST_PP_SEQ_SPLIT_203(x) (x) RTIBOOST_PP_SEQ_SPLIT_202
# define RTIBOOST_PP_SEQ_SPLIT_204(x) (x) RTIBOOST_PP_SEQ_SPLIT_203
# define RTIBOOST_PP_SEQ_SPLIT_205(x) (x) RTIBOOST_PP_SEQ_SPLIT_204
# define RTIBOOST_PP_SEQ_SPLIT_206(x) (x) RTIBOOST_PP_SEQ_SPLIT_205
# define RTIBOOST_PP_SEQ_SPLIT_207(x) (x) RTIBOOST_PP_SEQ_SPLIT_206
# define RTIBOOST_PP_SEQ_SPLIT_208(x) (x) RTIBOOST_PP_SEQ_SPLIT_207
# define RTIBOOST_PP_SEQ_SPLIT_209(x) (x) RTIBOOST_PP_SEQ_SPLIT_208
# define RTIBOOST_PP_SEQ_SPLIT_210(x) (x) RTIBOOST_PP_SEQ_SPLIT_209
# define RTIBOOST_PP_SEQ_SPLIT_211(x) (x) RTIBOOST_PP_SEQ_SPLIT_210
# define RTIBOOST_PP_SEQ_SPLIT_212(x) (x) RTIBOOST_PP_SEQ_SPLIT_211
# define RTIBOOST_PP_SEQ_SPLIT_213(x) (x) RTIBOOST_PP_SEQ_SPLIT_212
# define RTIBOOST_PP_SEQ_SPLIT_214(x) (x) RTIBOOST_PP_SEQ_SPLIT_213
# define RTIBOOST_PP_SEQ_SPLIT_215(x) (x) RTIBOOST_PP_SEQ_SPLIT_214
# define RTIBOOST_PP_SEQ_SPLIT_216(x) (x) RTIBOOST_PP_SEQ_SPLIT_215
# define RTIBOOST_PP_SEQ_SPLIT_217(x) (x) RTIBOOST_PP_SEQ_SPLIT_216
# define RTIBOOST_PP_SEQ_SPLIT_218(x) (x) RTIBOOST_PP_SEQ_SPLIT_217
# define RTIBOOST_PP_SEQ_SPLIT_219(x) (x) RTIBOOST_PP_SEQ_SPLIT_218
# define RTIBOOST_PP_SEQ_SPLIT_220(x) (x) RTIBOOST_PP_SEQ_SPLIT_219
# define RTIBOOST_PP_SEQ_SPLIT_221(x) (x) RTIBOOST_PP_SEQ_SPLIT_220
# define RTIBOOST_PP_SEQ_SPLIT_222(x) (x) RTIBOOST_PP_SEQ_SPLIT_221
# define RTIBOOST_PP_SEQ_SPLIT_223(x) (x) RTIBOOST_PP_SEQ_SPLIT_222
# define RTIBOOST_PP_SEQ_SPLIT_224(x) (x) RTIBOOST_PP_SEQ_SPLIT_223
# define RTIBOOST_PP_SEQ_SPLIT_225(x) (x) RTIBOOST_PP_SEQ_SPLIT_224
# define RTIBOOST_PP_SEQ_SPLIT_226(x) (x) RTIBOOST_PP_SEQ_SPLIT_225
# define RTIBOOST_PP_SEQ_SPLIT_227(x) (x) RTIBOOST_PP_SEQ_SPLIT_226
# define RTIBOOST_PP_SEQ_SPLIT_228(x) (x) RTIBOOST_PP_SEQ_SPLIT_227
# define RTIBOOST_PP_SEQ_SPLIT_229(x) (x) RTIBOOST_PP_SEQ_SPLIT_228
# define RTIBOOST_PP_SEQ_SPLIT_230(x) (x) RTIBOOST_PP_SEQ_SPLIT_229
# define RTIBOOST_PP_SEQ_SPLIT_231(x) (x) RTIBOOST_PP_SEQ_SPLIT_230
# define RTIBOOST_PP_SEQ_SPLIT_232(x) (x) RTIBOOST_PP_SEQ_SPLIT_231
# define RTIBOOST_PP_SEQ_SPLIT_233(x) (x) RTIBOOST_PP_SEQ_SPLIT_232
# define RTIBOOST_PP_SEQ_SPLIT_234(x) (x) RTIBOOST_PP_SEQ_SPLIT_233
# define RTIBOOST_PP_SEQ_SPLIT_235(x) (x) RTIBOOST_PP_SEQ_SPLIT_234
# define RTIBOOST_PP_SEQ_SPLIT_236(x) (x) RTIBOOST_PP_SEQ_SPLIT_235
# define RTIBOOST_PP_SEQ_SPLIT_237(x) (x) RTIBOOST_PP_SEQ_SPLIT_236
# define RTIBOOST_PP_SEQ_SPLIT_238(x) (x) RTIBOOST_PP_SEQ_SPLIT_237
# define RTIBOOST_PP_SEQ_SPLIT_239(x) (x) RTIBOOST_PP_SEQ_SPLIT_238
# define RTIBOOST_PP_SEQ_SPLIT_240(x) (x) RTIBOOST_PP_SEQ_SPLIT_239
# define RTIBOOST_PP_SEQ_SPLIT_241(x) (x) RTIBOOST_PP_SEQ_SPLIT_240
# define RTIBOOST_PP_SEQ_SPLIT_242(x) (x) RTIBOOST_PP_SEQ_SPLIT_241
# define RTIBOOST_PP_SEQ_SPLIT_243(x) (x) RTIBOOST_PP_SEQ_SPLIT_242
# define RTIBOOST_PP_SEQ_SPLIT_244(x) (x) RTIBOOST_PP_SEQ_SPLIT_243
# define RTIBOOST_PP_SEQ_SPLIT_245(x) (x) RTIBOOST_PP_SEQ_SPLIT_244
# define RTIBOOST_PP_SEQ_SPLIT_246(x) (x) RTIBOOST_PP_SEQ_SPLIT_245
# define RTIBOOST_PP_SEQ_SPLIT_247(x) (x) RTIBOOST_PP_SEQ_SPLIT_246
# define RTIBOOST_PP_SEQ_SPLIT_248(x) (x) RTIBOOST_PP_SEQ_SPLIT_247
# define RTIBOOST_PP_SEQ_SPLIT_249(x) (x) RTIBOOST_PP_SEQ_SPLIT_248
# define RTIBOOST_PP_SEQ_SPLIT_250(x) (x) RTIBOOST_PP_SEQ_SPLIT_249
# define RTIBOOST_PP_SEQ_SPLIT_251(x) (x) RTIBOOST_PP_SEQ_SPLIT_250
# define RTIBOOST_PP_SEQ_SPLIT_252(x) (x) RTIBOOST_PP_SEQ_SPLIT_251
# define RTIBOOST_PP_SEQ_SPLIT_253(x) (x) RTIBOOST_PP_SEQ_SPLIT_252
# define RTIBOOST_PP_SEQ_SPLIT_254(x) (x) RTIBOOST_PP_SEQ_SPLIT_253
# define RTIBOOST_PP_SEQ_SPLIT_255(x) (x) RTIBOOST_PP_SEQ_SPLIT_254
# define RTIBOOST_PP_SEQ_SPLIT_256(x) (x) RTIBOOST_PP_SEQ_SPLIT_255
#
# endif
