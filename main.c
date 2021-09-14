#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main( )
{
	// Variáveis de loop
	int i, j;
	
	// Matriz dos ovos
	int ovos[ 20 ][ 20 ] = { 0 };
	
	// Melhor soma e linha de ovos
	int melhor_pos[ 2 ][ 2 ];
	int melhor_soma = -1;
	
	// Controla se os ovos foram gerados
	bool gerou = false;
	
	// Inicializa os números aleatórios
	srand( time( NULL ) );  
	
	// Loop infinito para o menu
	while( true )
	{
		// Limpa a tela
		system( "cls" );
		
		// Varíavel correspondente à opção no menu
		int opt = 0;
		
		printf( "[1] Gerar os valores para os ovos.\n" );
		printf( "[2] Mostrar todos os ovos.\n" );
		printf( "[3] Mostrar ovo especifico.\n" );
		printf( "[4] Encontrar melhores ovos.\n" );
		printf( "[5] Sair.\n" );
		
		printf( "\nOpcao: " );
		
		scanf( "%d", &opt );
		
		printf( "\n" );
		
		// Age baseado nas opções
		switch ( opt )
		{
		case 1:	// Gerar matriz de ovos
			for ( i = 0; i < 20; i++ )
				for ( j = 0; j < 20; j++ )
					ovos[ i ][ j ] = rand( ) % 99;
					
			printf( "Ovos gerados" );
			gerou = true;
			
			break;
		
		case 2:	// Mostrar a matriz
			if ( !gerou )	// Checar se já geramos a matriz
			{
				printf( "Ovos ainda nao gerados!\n" );
				system( "pause" );
				continue;
			}
			
			printf( "Ovos:\n\n" );
	
			for ( i = 0; i < 20; i++ )
			{
				for ( j = 0; j < 20; j++ )
					printf( "%02d ", ovos[ i ][ j ] );
				
				printf( "\n" );
			}
			
			break;
			
		case 3:	// Mostrar ovo específico
			if ( !gerou )	// Checar se já geramos a matriz
			{
				printf( "Ovos ainda nao gerados!\n" );
				system( "pause" );
				continue;
			}
			
			printf( "Digite a posicao do ovo (separada por espaco): " );
			
			// Salva a posição em uma array
			int pos_ovo[ 2 ];
			scanf( "%d %d", &pos_ovo[ 0 ], &pos_ovo[ 1 ] );
			
			// Mostra o valor do ovo
			printf( "O ovo na posicao %02d, %02d tem o valor: %d", pos_ovo[ 0 ], pos_ovo[ 1 ], ovos[ pos_ovo[ 0 ] ][ pos_ovo[ 1 ] ] );
			
			break;
			
		case 4:	// Encontrar a melhor fila 
			if ( !gerou )	// Checar se já geramos a matriz
			{
				printf( "Ovos ainda nao gerados!\n" );
				system( "pause" );
				continue;
			}
			
			for ( i = 0; i < 20; i++ ) 						// Linhas
			{
				for ( j = 0; j < 20; j++ )					// Colunas
				{
					int soma_atual;
					
					if ( i < 16 )							// Checagem para baixo
					{
						// Soma diretamente para baixo
						soma_atual = 	ovos[ i ][ j ] + ovos[ i + 1 ][ j ] + 
										ovos[ i + 2 ][ j ] + ovos[ i + 3 ][ j ] + 
										ovos[ i + 4 ][ j ];
										
						if ( soma_atual > melhor_soma )		// Se a soma atual for maior que a salva, sobrescrevemos a soma e a posição
						{
							melhor_soma = soma_atual;
							melhor_pos[ 0 ][ 0 ] = i;
							melhor_pos[ 0 ][ 1 ] = j;
							
							melhor_pos[ 1 ][ 0 ] = i + 4;
							melhor_pos[ 1 ][ 1 ] = j;
						}
						
						if ( j > 4 )
						{
							// Soma para diagonal esquerda
							soma_atual = 	ovos[ i ][ j ] + ovos[ i + 1 ][ j - 1 ] + 
											ovos[ i + 2 ][ j - 2 ] + ovos[ i + 3 ][ j - 3 ] + 
											ovos[ i + 4 ][ j - 4 ];
											
							if ( soma_atual > melhor_soma )		// Se a soma atual for maior que a salva, sobrescrevemos a soma e a posição
							{
								melhor_soma = soma_atual;
								melhor_pos[ 0 ][ 0 ] = i;
								melhor_pos[ 0 ][ 1 ] = j;
								
								melhor_pos[ 1 ][ 0 ] = i + 4;
								melhor_pos[ 1 ][ 1 ] = j - 4;
							}
						}
						
						if ( j < 16 )
						{
							// Soma para diagonal direita
							soma_atual = 	ovos[ i ][ j ] + ovos[ i + 1 ][ j + 1 ] + 
											ovos[ i + 2 ][ j + 2 ] + ovos[ i + 3 ][ j + 3 ] + 
											ovos[ i + 4 ][ j + 4 ];
											
							if ( soma_atual > melhor_soma )		// Se a soma atual for maior que a salva, sobrescrevemos a soma e a posição
							{
								melhor_soma = soma_atual;
								melhor_pos[ 0 ][ 0 ] = i;
								melhor_pos[ 0 ][ 1 ] = j;
								
								melhor_pos[ 1 ][ 0 ] = i + 4;
								melhor_pos[ 1 ][ 1 ] = j + 4;
							}
							
							// Soma para direita
							soma_atual = 	ovos[ i ][ j ] + ovos[ i ][ j + 1 ] + 
											ovos[ i ][ j + 2 ] + ovos[ i ][ j + 3 ] + 
											ovos[ i ][ j + 4 ];
											
							if ( soma_atual > melhor_soma )		// Se a soma atual for maior que a salva, sobrescrevemos a soma e a posição
							{
								melhor_soma = soma_atual;
								melhor_pos[ 0 ][ 0 ] = i;
								melhor_pos[ 0 ][ 1 ] = j;
								
								melhor_pos[ 1 ][ 0 ] = i;
								melhor_pos[ 1 ][ 1 ] = j + 4;
							}
						}
					}
					else	// Estamos nas ultimas linhas, então a única checagem necessaria é para a direita
					{
						if ( j < 16 )
						{
							// Soma para direita
							soma_atual = 	ovos[ i ][ j ] + ovos[ i ][ j + 1 ] + 
											ovos[ i ][ j + 2 ] + ovos[ i ][ j + 3 ] + 
											ovos[ i ][ j + 4 ];
											
							if ( soma_atual > melhor_soma )		// Se a soma atual for maior que a salva, sobrescrevemos a soma e a posição
							{
								melhor_soma = soma_atual;
								melhor_pos[ 0 ][ 0 ] = i;
								melhor_pos[ 0 ][ 1 ] = j;
								
								melhor_pos[ 1 ][ 0 ] = i;
								melhor_pos[ 1 ][ 1 ] = j + 4;
							}
						}
					}
				}
			}
			
			printf( "Ovos:\n\n" );
			
			printf( "     " );
			
			for ( i = 0; i < 20; i++ )
				printf( "%02d ", i );
				
			printf( "\n\n" );
	
			for ( i = 0; i < 20; i++ )
			{
				printf( "%02d   ", i );
				
				for ( j = 0; j < 20; j++ )
					printf( "%02d ", ovos[ i ][ j ] );
				
				printf( "\n" );
			}
			
			printf( "\n" );
			
			printf( "A melhor sequencia de ovos esta da posicao %02d, %02d ate a posicao %02d, %02d e tem a soma: %d\n", melhor_pos[ 0 ][ 0 ], melhor_pos[ 0 ][ 1 ], melhor_pos[ 1 ][ 0 ], melhor_pos[ 1 ][ 1 ], melhor_soma );
			
			break;
			
		case 5:	// Apenas termina o programa
			return 0;
			
		}
		
		printf( "\n" );
		system( "pause" );
	}
}
