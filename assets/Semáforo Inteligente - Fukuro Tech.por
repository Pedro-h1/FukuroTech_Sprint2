programa
{
    funcao esperar(inteiro segundos)
    {
        inteiro i, j

        para (i = 1; i <= segundos; i++)
        {
            para (j = 1; j <= 10000000; j++)
            {
            }
        }
    }

    funcao inicio()
    {
        inteiro perfil

        enquanto (verdadeiro)
        {
            limpa()

            // FASE 1
            escreva("=== FASE 1 ===\n")
            escreva("Carros: VERDE\n")
            escreva("Pedestres: VERMELHO\n")
            escreva("Faixa: VERMELHA\n\n")
            escreva("Digite qual é o seu perfil (1 - Autista, 2 - Cadeirante, 3 - Visual, 4 - Idoso): ")
            leia(perfil)

            se (perfil == 1)
            {
                limpa()
                escreva("=== MODO AUTISTA ===\n")
                escreva("Tempo de travessia: 15 segundos\n")
                esperar(6)
                limpa()

                // FASE 2
                escreva("=== FASE 2 ===\n")
                escreva("Carros: AMARELO\n")
                escreva("Pedestres: VERMELHO\n")
                escreva("Faixa: VERMELHA\n")
                escreva("Tempo da fase: 2 segundos\n")
                esperar(4)

                limpa()

                // FASE 3
                escreva("=== FASE 3 ===\n")
                escreva("Carros: VERMELHO\n")
                escreva("Pedestres: VERDE\n")
                escreva("Faixa: VERDE\n")
                escreva("Tempo da fase: 15 segundos\n")
                esperar(15)

                limpa()

                // FASE 4
                escreva("=== FASE 4 ===\n")
                escreva("Carros: AMARELO\n")
                escreva("Pedestres: VERMELHO\n")
                escreva("Faixa: VERMELHA\n")
                escreva("Tempo da fase: 2 segundos\n")
                esperar(4)
            }
            senao
            {
                se (perfil == 2)
                {
                    limpa()
                    escreva("=== MODO CADEIRANTE ===\n")
                    escreva("Tempo de travessia: 20 segundos\n")
                    esperar(6)
                    limpa()

                    // FASE 2
                    escreva("=== FASE 2 ===\n")
                    escreva("Carros: AMARELO\n")
                    escreva("Pedestres: VERMELHO\n")
                    escreva("Faixa: VERMELHA\n")
                    escreva("Tempo da fase: 2 segundos\n")
                    esperar(4)

                    limpa()

                    // FASE 3
                    escreva("=== FASE 3 ===\n")
                    escreva("Carros: VERMELHO\n")
                    escreva("Pedestres: VERDE\n")
                    escreva("Faixa: VERDE\n")
                    escreva("Som: Um bip curto\n")
                    escreva("Tempo da fase: 20 segundos\n")
                    esperar(20)

                    limpa()

                    // FASE 4
                    escreva("=== FASE 4 ===\n")
                    escreva("Carros: AMARELO\n")
                    escreva("Pedestres: VERMELHO\n")
                    escreva("Faixa: VERMELHA\n")
                    escreva("Som: Um bip curto\n")
                    escreva("Tempo da fase: 2 segundos\n")
                    esperar(4)
                }
                senao
                {
                    se (perfil == 3)
                    {
                        limpa()
                        escreva("=== MODO DEFICIENTE VISUAL ===\n")
                        escreva("Tempo de travessia: 18 segundos\n")
                        esperar(6)
                        limpa()

                        // FASE 2
                        escreva("=== FASE 2 ===\n")
                        escreva("Carros: AMARELO\n")
                        escreva("Pedestres: VERMELHO\n")
                        escreva("Faixa: VERMELHA\n")
                        escreva("Tempo da fase: 2 segundos\n")
                        esperar(4)

                        limpa()

                        // FASE 3
                        escreva("=== FASE 3 ===\n")
                        escreva("Carros: VERMELHO\n")
                        escreva("Pedestres: VERDE\n")
                        escreva("Faixa: VERDE\n")
                        escreva("Som: Bips contínuos aumentando a velocidade\n")
                        escreva("Tempo da fase: 18 segundos\n")
                        esperar(18)

                        limpa()

                        // FASE 4
                        escreva("=== FASE 4 ===\n")
                        escreva("Carros: AMARELO\n")
                        escreva("Pedestres: VERMELHO\n")
                        escreva("Faixa: VERMELHA\n")
                        escreva("Som: Bips contínuos aumentando a velocidade e ao fim um bip agudo\n")
                        escreva("Tempo da fase: 2 segundos\n")
                        esperar(4)
                    }
                    senao
                    {
                        se (perfil == 4)
                        {
                            limpa()
                            escreva("=== MODO IDOSO ===\n")
                            escreva("Tempo de travessia: 20 segundos\n")
                            esperar(6)
                            limpa()

                            // FASE 2
                            escreva("=== FASE 2 ===\n")
                            escreva("Carros: AMARELO\n")
                            escreva("Pedestres: VERMELHO\n")
                            escreva("Faixa: VERMELHA\n")
                            escreva("Tempo da fase: 2 segundos\n")
                            esperar(4)

                            limpa()

                            // FASE 3
                            escreva("=== FASE 3 ===\n")
                            escreva("Carros: VERMELHO\n")
                            escreva("Pedestres: VERDE\n")
                            escreva("Faixa: VERDE\n")
                            escreva("Som: 1 Bip curto agudo\n")
                            escreva("Tempo da fase: 20 segundos\n")
                            esperar(20)

                            limpa()

                            // FASE 4
                            escreva("=== FASE 4 ===\n")
                            escreva("Carros: AMARELO\n")
                            escreva("Pedestres: VERMELHO\n")
                            escreva("Faixa: VERMELHA\n")
                            escreva("Som: 4 Bips curtos agudos e 1 curto médio\n")
                            escreva("Tempo da fase: 2 segundos\n")
                            esperar(4)
                        }
                    }
                }
            }
        }
    }
}