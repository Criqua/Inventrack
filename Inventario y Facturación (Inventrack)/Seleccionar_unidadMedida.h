#pragma once
#include "Productos_vendidos.h"

namespace Inventrack {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Seleccionar_unidadMedida
	/// </summary>
	public ref class Seleccionar_unidadMedida : public System::Windows::Forms::Form
	{
	public:
		Seleccionar_unidadMedida(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Seleccionar_unidadMedida()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_unitario;
	private: System::Windows::Forms::Button^ btn_peso;
	private: System::Windows::Forms::Button^ btn_volumen;
	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btn_unitario = (gcnew System::Windows::Forms::Button());
			this->btn_peso = (gcnew System::Windows::Forms::Button());
			this->btn_volumen = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_unitario
			// 
			this->btn_unitario->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btn_unitario->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_unitario->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->btn_unitario->Location = System::Drawing::Point(4, 8);
			this->btn_unitario->Name = L"btn_unitario";
			this->btn_unitario->Size = System::Drawing::Size(424, 49);
			this->btn_unitario->TabIndex = 4;
			this->btn_unitario->Text = L"   Por unidades";
			this->btn_unitario->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_unitario->UseVisualStyleBackColor = false;
			this->btn_unitario->Click += gcnew System::EventHandler(this, &Seleccionar_unidadMedida::btn_unitario_Click);
			// 
			// btn_peso
			// 
			this->btn_peso->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btn_peso->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_peso->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->btn_peso->Location = System::Drawing::Point(4, 63);
			this->btn_peso->Name = L"btn_peso";
			this->btn_peso->Size = System::Drawing::Size(424, 49);
			this->btn_peso->TabIndex = 5;
			this->btn_peso->Text = L"   Por peso";
			this->btn_peso->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_peso->UseVisualStyleBackColor = false;
			this->btn_peso->Click += gcnew System::EventHandler(this, &Seleccionar_unidadMedida::btn_peso_Click);
			// 
			// btn_volumen
			// 
			this->btn_volumen->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btn_volumen->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_volumen->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 10, System::Drawing::FontStyle::Bold));
			this->btn_volumen->Location = System::Drawing::Point(4, 118);
			this->btn_volumen->Name = L"btn_volumen";
			this->btn_volumen->Size = System::Drawing::Size(424, 49);
			this->btn_volumen->TabIndex = 6;
			this->btn_volumen->Text = L"   Por volumen";
			this->btn_volumen->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_volumen->UseVisualStyleBackColor = false;
			this->btn_volumen->Click += gcnew System::EventHandler(this, &Seleccionar_unidadMedida::btn_volumen_Click);
			// 
			// Seleccionar_unidadMedida
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(432, 177);
			this->Controls->Add(this->btn_volumen);
			this->Controls->Add(this->btn_peso);
			this->Controls->Add(this->btn_unitario);
			this->MaximizeBox = false;
			this->Name = L"Seleccionar_unidadMedida";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Seleccione una opción";
			this->Load += gcnew System::EventHandler(this, &Seleccionar_unidadMedida::Seleccionar_unidadMedida_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Seleccionar_unidadMedida_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_unitario_Click(System::Object^ sender, System::EventArgs^ e) {
		// Creamos una nueva instancia del formulario de "Productos_vendidos.h" y le pasamos el tipo de unidad seleccionado
		Inventrack::Productos_vendidos^ comprod = gcnew Inventrack::Productos_vendidos();
		comprod->tipoMedida = "unidad";
		comprod->Show();
	}
	private: System::Void btn_peso_Click(System::Object^ sender, System::EventArgs^ e) {
		// Creamos una nueva instancia del formulario de "Productos_vendidos.h" y le pasamos el tipo de unidad seleccionado
		Inventrack::Productos_vendidos^ comprod = gcnew Inventrack::Productos_vendidos();
		comprod->tipoMedida = "peso";
		comprod->Show();
	}
	private: System::Void btn_volumen_Click(System::Object^ sender, System::EventArgs^ e) {
		// Creamos una nueva instancia del formulario de "Productos_vendidos.h" y le pasamos el tipo de unidad seleccionado
		Inventrack::Productos_vendidos^ comprod = gcnew Inventrack::Productos_vendidos();
		comprod->tipoMedida = "volumen";
		comprod->Show();
	}
	};
}
